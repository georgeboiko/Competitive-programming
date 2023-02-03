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
	ll n, m, k, s, f;
	cin >> n >> m >> k >> s >> f; --s, --f;
	vector<Edge>edges;
	vector<vector<ll>>matrix(n, vector<ll>(n, INF));
	for (ll i = 0; i < m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w; --u, --v;
		if (w < matrix[u][v]) {
			matrix[u][v] = w;
		}
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			if (matrix[i][j] < INF) {
				edges.push_back(Edge(i, j, matrix[i][j]));
			}
		}
	}
    vector<vector<ll>>d(n, vector<ll>(k + 1, INF));
    d[s][0] = 0;
    for (ll x = 0; x < n; x++) {
        for (ll i = 0; i < k; i++) {
            for (ll j = 0; j < edges.size(); j++) {
                if (d[edges[j].from][i] < INF) {
                    if (d[edges[j].to][i + 1] > d[edges[j].from][i] + edges[j].w) {
                        d[edges[j].to][i + 1] = d[edges[j].from][i] + edges[j].w;
                    }
                }
            }
        }
    }
    ll ans = INF;
    for (ll i = 0; i <= k; i++) {
		ans = min(d[f][i], ans);
    }
	if (ans == INF) {
		cout << -1 << el;
	}
	else cout << ans << el;
}
