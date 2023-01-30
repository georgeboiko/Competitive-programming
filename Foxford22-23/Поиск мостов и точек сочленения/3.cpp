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
vector<ll>sch;

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
				//ans.insert(v + 1);
				sch[v] = 1;
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
	gr.resize(n + m);
	tin.resize(n + m);
	dp.resize(n + m);
	used.resize(n + m);
	sch.resize(n + m);
	for (ll i = 0; i < m; ++i) {
		ll u, v, x;
		cin >> u >> v >> x; --u, --v, --x;
		gr[n + i].push_back(u);
		gr[n + i].push_back(v);
		gr[n + i].push_back(x);
		gr[u].push_back(n + i);
		gr[v].push_back(n + i);
		gr[x].push_back(n + i);
	}
	for (ll i = 0; i < n; ++i) {
		if (!used[i]) dfs(i);
	}
	ll cnt = 0;
	for (ll i = n; i < n + m; ++i) {
		if (sch[i] == 1) ++cnt;
	}
	cout << cnt << el;
	if (cnt == 0) return 0;
	for (ll i = n; i < n + m; ++i) {
		if (sch[i] == 1) cout << i - n + 1 << " ";
	}
	cout << el;
}
