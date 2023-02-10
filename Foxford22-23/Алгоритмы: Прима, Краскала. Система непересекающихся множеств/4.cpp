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

inline bool operator < (const Edge& a, const Edge& b) {
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

struct ASK {
	string type;
	ll x, y;
	ASK() {}
	ASK(string type, ll x, ll y) : type(type), x(x), y(y) {}
};

int main() {
	fastIO;
	ll n, m, k;
	cin >> n >> m >> k;
	init(n);
	vector<Edge>edges;
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v; --u, --v;
		edges.push_back(Edge(u, v, 1, i));
	}
	vector<ASK>q;
	for (ll i = 0; i < k; ++i) {
		string type;
		ll u, v;
		cin >> type >> u >> v;
		--u, --v;
		q.push_back(ASK(type, u, v));
	}
	vector<string>ans;
	reverse(all(q));
	for (auto& ask : q) {
		if (ask.type == "cut") {
			unite(ask.x, ask.y);
		}
		if (ask.type == "ask") {
			if (get_par(ask.x) == get_par(ask.y)) ans.push_back("YES");
			else ans.push_back("NO");
		}
	}
	reverse(all(ans));
	for (string& i : ans) cout << i << el;
}
