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

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e14;

ll t = 0;
vector<vector<ll>>gr;
vector<ll> tin, dp;
set<ll>ans;
vector<bool>used;

void dfs(ll v, ll p = -1) {
	used[v] = true;
	tin[v] = dp[v] = t++;
	ll ch = 0;
	for (ll u : gr[v]) {
		if (u == p) continue;
		if (used[u]) dp[v] = min(dp[v], tin[u]);
		else {
			dfs(u, v);
			dp[v] = min(dp[u], dp[v]);
			if (dp[u] >= tin[v] && p != -1) {
				ans.insert(v + 1);
			}
			++ch;
		}
	}
	if (p == -1 && ch > 1) {
		ans.insert(v + 1);
	}
}

int main() {
	fastIO;
	ll n, m;
	cin >> n >> m;
	gr.resize(n);
	tin.resize(n);
	dp.resize(n);
	used.resize(n);
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v; --u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for (ll i = 0; i < n; ++i) {
		if (!used[i]) dfs(i);
	}
	cout << ans.size() << el;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << el;
}
