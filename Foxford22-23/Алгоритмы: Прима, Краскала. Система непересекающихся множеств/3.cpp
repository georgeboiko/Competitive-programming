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

int main() {
	fastIO;
	ll n, m;
	cin >> n >> m;
	init(n);
	vector<ll>ans;
	ll answ = n - 1;
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;// --x, --y;
		if (get_par(x) != get_par(y)) {
			unite(x, y);
			--answ;
			if (answ <= 0) {
				cout << i + 1 << el;
				return 0;
			}
		}
	}
	cout << answ+1 << el;
}
