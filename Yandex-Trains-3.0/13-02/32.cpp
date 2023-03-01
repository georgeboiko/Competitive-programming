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

vector<vector<ll>> g;
vector<ll> colors, tin, tout;
ll t = 0;
bool ans = false;

void dfs(ll u) {
    if (u == 0) ans = true;
    colors[u] = 1;
    tin[u] = t++;
    for (auto v : g[u]) {
        if (colors[v] == 0) {
            if (v == 0) ans = true;
            dfs(v);
        }
    }
    colors[u] = 2;
    tout[u] = t++;
}

int main() {
	fastIO;
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    colors.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v; --u, --v;
        g[u].push_back(v);
    }
    for (ll i = 0; i < n; ++i) {
        dfs(i);
        if (ans) cout << i+1 << " ";
        colors.clear(); colors.resize(n);
        tin.clear(); tin.resize(n);
        tout.clear(); tout.resize(n);
        t = 0; ans = false;
    }
}
