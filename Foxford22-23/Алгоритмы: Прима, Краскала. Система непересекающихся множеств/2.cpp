/*#include <iostream>
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
	ll u, v, num; ld w;
	Edge() {}
	Edge(ll u, ll v, ld w, ll num) : u(u), v(v), w(w), num(num) {}
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
	ll n;
	cin >> n;
	init(n);
	vector<Edge>edges;
	vector<pair<ld, ld>>coords;
	for (ll i = 0; i < n; ++i) {
		ld x, y;
		cin >> x >> y;
		coords.push_back({ x,y });
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = i+1; j < n; ++j) {
			edges.push_back(Edge(i, j, hypot(abs(coords[i].first - coords[j].first), abs(coords[i].second-coords[j].second)), i+j));
		}
	}
	sort(all(edges));
	vector<ll>ans;
	ld answ = 0;
	for (auto& e : edges) {
		if (get_par(e.u) != get_par(e.v)) {
			unite(e.u, e.v);
			ans.push_back(e.num);
			answ += e.w;
		}
	}
	cout << fixed;
	cout.precision(15);
	cout << answ << el;
}      ЭТО РЕШЕНИЕ С АЛГОРИТМОМ КРАСКАЛА ВЫДАЕТ ML*/ 
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

ld dist2(ll i, ll j, vector<ld>& x, vector<ld>& y) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
	fastIO;
	ll n;
	cin >> n;
	vector<ld>x(n), y(n), min_e(n, INF), end_e(n, -1), used(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
    ld dist = min_e[1] = 0;
    for (ll i = 0; i < n; ++i) {
        ll v = -1;
        for (ll j = 0; j < n; ++j){
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        used[v] = 1;
        if (end_e[v] != -1) {
            dist += sqrt(dist2(v, end_e[v], x, y));
        }
        for (ll j = 0; j < n; ++j) {
            ld dV_TO = dist2(v, j, x, y);
            if (!used[j] && (dV_TO < min_e[j])) {
                min_e[j] = dV_TO;
                end_e[j] = v;
            }
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << dist << el;
}
