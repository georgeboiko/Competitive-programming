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

int main() {
	fastIO;
	ll n, m, a, b;
	cin >> n >> m >> a >> b; --a, --b;
	vector<vector<ll>>gr(n);
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v; --u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	queue<ll>q;
	vector<ll>d(n, INF), p(n, -1);
	d[a] = 0;
	q.push(a);
	while (!q.empty()) {
		ll v = q.front(); q.pop();
		for (ll u : gr[v]) {
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				p[u] = v;
				q.push(u);
			}
		}
	}
	if (d[b] == INF) {
		cout << -1 << el;
		return 0;
	}
	vector<ll>ans;
	ll cur = b;
	while (cur != -1) {
		ans.push_back(cur);
		cur = p[cur];
	}
	reverse(all(ans));
	cout << d[b] << el;
	for (ll i : ans) cout << i+1 << " ";
	cout << el;
}
