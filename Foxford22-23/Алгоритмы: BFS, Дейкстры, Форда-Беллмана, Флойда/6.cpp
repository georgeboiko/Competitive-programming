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
	ll from, to, w;
	Edge() {}
	Edge(ll from, ll to, ll w) : from(from), to(to), w(w) {}
};

int main() {
	fastIO;
	ll n, m;
	cin >> n >> m;
	vector<Edge>edges;
	for (ll i = 0; i < m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w; --u, --v;
		edges.push_back(Edge(u, v, w));
	}
	vector<ll>d(n, INF);
	d[0] = 0;
	for (ll i = 0; i < n - 1; ++i) {
		for (auto& e : edges) {
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.w) {
				d[e.to] = d[e.from] + e.w;
			}
		}
	}
	for (ll i : d) {
		if (i == INF) cout << 30000 << " ";
		else cout << i << " ";
	}
	cout << el;
}
