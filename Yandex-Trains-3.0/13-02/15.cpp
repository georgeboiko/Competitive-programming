#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e14;

string s;
string chars = "</>qwertyuiopasdfghjklzxcvbnm";
ll openCnt = 0, closeCnt = 0, slashesCnt = 0;
map<char, ll> mp;

bool check(string s) {
    if (s[0] != '<' || s[s.size() - 1] != '>') return 0;
    vector<string> open;
    ll i = 0;
    while (i < s.size()) {
        if (s[i] != '<') return 0;
        ++i;
        ll closing = 0;
        if (s[i] == '/') {
            closing = 1;
            ++i;
        }
        if (!('a' <= s[i] && s[i] <= 'z')) return 0;
        string tag = "";
        tag.push_back(s[i]);
        ++i;
        while ('a' <= s[i] && s[i] <= 'z') {
            tag.push_back(s[i]);
            ++i;
        }
        if (s[i] != '>') return 0;
        ++i;
        if (closing == 0) open.push_back(tag);
        else {
            if (open.size() == 0) return 0;
            if (open.back() != tag) return 0;
            open.pop_back();
        }
    }
    return (open.size() == 0);
}

void solve(char c) {
    for (ll i = 0; i < s.size(); ++i) {
        string t = s;
        t[i] = c;
        if (check(t)) {
            cout << t << el;
            exit(0);
        }
    }
}

int main() {
    fastIO;
    cin >> s;
    for (auto x : s) {
        if (x == '<') openCnt++;
        else if (x == '>') closeCnt++;
        else if (x == '/') slashesCnt++;
        else mp[x] = mp[x] + 1;
    }
    for (auto x : chars) {
        if (x == '<' && openCnt % 2) solve(x);
        if (x == '>' && closeCnt % 2) solve(x);
        if (x == '/' && closeCnt / 2 != slashesCnt) solve(x);
        if (mp.count(x) && (mp[x] % 2)) solve(x);
    }
}
