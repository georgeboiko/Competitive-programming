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

int fr(int x) {
    return (x % 10) * 1000 + x / 10;
}

int fl(int x) {
    return (x % 1000) * 10 + x / 1000;
}

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    vector<int> p((int)1e5);
    vector<bool> used((int)1e5);
    queue<int> q;
    used[n] = 1;
    q.push(n);
    while (q.front() != m) {
        int v = q.front(); q.pop();
        if (v / 1000 != 9 && !used[v + 1000]) {
            q.push(v + 1000);
            p[v + 1000] = v;
            used[v + 1000] = 1;
        }
        if (v % 10 != 1 && !used[v - 1]) {
            q.push(v - 1);
            p[v - 1] = v;
            used[v - 1] = 1;
        }
        if (!used[fr(v)]) {
            q.push(fr(v));
            p[fr(v)] = v;
            used[fr(v)] = 1;
        }
        if (!used[fl(v)]) {
            q.push(fl(v));
            p[fl(v)] = v;
            used[fl(v)] = 1;
        }
    }
    vector<int> path;
    for (int v = m; v != n; v = p[v]) path.push_back(v);
    path.push_back(n);
    reverse(all(path));
    for (auto x : path) cout << x << el;
}
