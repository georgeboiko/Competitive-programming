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

struct Edge {
	ll u, v, w, num;
	Edge() {}
	Edge(ll u, ll v, ll w, ll num) : u(u), v(v), w(w), num(num) {}
};

inline bool operator < (const Edge& a, const Edge& b){
	return a.w < b.w;
}

vector<ll> p, d;

void init(ll n) {
	p.resize(n);
	d.resize(n);
	iota(all(p), 0);
}

ll get_par(ll v) {
	if (v == p[v]) return v;
	return p[v] = get_par(p[v]);
}

void unite(ll u, ll v) {
	u = get_par(u);
	v = get_par(v);
	if (u != v) {
		if (d[u] > d[v]) swap(u, v);
		p[u] = v;
		if (d[v] == d[u]) ++d[v];
	}
}

int main() {
	fastIO;
	ll n, m;
	cin >> n >> m;
	init(n);
	vector<Edge>edges;
	for (ll i = 0; i < m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w;
		edges.push_back(Edge(u - 1, v - 1, w, i));
	}
	sort(all(edges));
	vector<ll>ans;
	ll answ = 0;
	for (auto& e : edges) {
		if (get_par(e.u) != get_par(e.v)) {
			unite(e.u, e.v);
			ans.push_back(e.num);
			answ += e.w;
		}
	}
	cout << answ << el;
}
