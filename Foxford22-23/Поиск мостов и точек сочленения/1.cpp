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

struct Edge {
	ll to, num;
	bool is_bridge;
	Edge() {}
	Edge(ll _to, ll _num) {
		to = _to;
		num = _num;
		is_bridge = false;
	}
};

ll n, m;
vector<vector<ll>>gr;
vector<Edge>edges;
vector<bool>used;
vector<ll>d, dp;
vector<ll>ans;
vector<ll>comp;
vector<vector<ll>>comps;
vector<vector<ll>>cgr;

void dfs(ll v, ll depth = 0, ll p = -1) {
	used[v] = true;
	d[v] = depth;
	for (ll e : gr[v]) {
		ll u = edges[e].to;
		ll num = edges[e].num;
		if (!used[u]) {
			dfs(u, depth + 1, num);
			dp[v] = min(dp[v], dp[u]);
		}
		else if (num != p) {
			dp[v] = min(dp[v], d[u]);
		}
	}
	if (p != -1 && dp[v] >= d[v]) {
		ans.push_back(p + 1);
		edges[2 * p].is_bridge = true;
		edges[2 * p + 1].is_bridge = true;
	}
}

void dfs2(ll v, ll cur_comp) {
	used[v] = true;
	comp[v] = cur_comp;
	comps[cur_comp].push_back(v+1);
	for (ll e : gr[v]) {
		ll u = edges[e].to;
		if (!edges[e].is_bridge) {
			if (!used[u]) dfs2(u, cur_comp);
			else if (used[u]) {
				cgr[cur_comp].push_back(comp[u]);
				cgr[comp[u]].push_back(cur_comp);
			}
		}
	}
}

int main() {
	fastIO;
	cin >> n >> m;
	gr.resize(n);
	edges.reserve(2 * m);
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v; --u, --v;
		edges.push_back(Edge(v, i));
		edges.push_back(Edge(u, i));
		gr[u].push_back(2 * i);
		gr[v].push_back(2 * i + 1);
	}
	used.resize(n);
	d.resize(n);
	dp.resize(n, INF);
	for (ll i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
	used.assign(n, false);
	comp.resize(n);
	ll cur_comp = 0;
	for (ll i = 0; i < n; ++i) {
		if (!used[i]) {
			cgr.push_back(vector<ll>());
			comps.push_back(vector<ll>());
			dfs2(i, cur_comp++);
		}
	}
	cout << cur_comp << el;
	for (auto& i : comps) {
		sort(all(i));
	}
	sort(all(comps));
	for (auto i : comps) {
		for (ll j : i) {
			cout << j << " ";
		}
		cout << el;
	}
}
