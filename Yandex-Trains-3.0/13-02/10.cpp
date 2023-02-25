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

int main() {
	fastIO;
	string s;
	cin >> s;
	map<char, ll>mp;
	for (ll i = 0; i < s.size(); ++i) {
		mp[s[i]] += (i + 1) * (s.size() - i);
	}
	for (auto x : mp) {
		cout << x.first << ": " << x.second << el;
	}
}
