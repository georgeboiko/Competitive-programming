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
	ll n;
	cin >> n;
	vector<ll>costs(n);
	vector<vector<pair<ll, ll>>>gr(n);
	for (ll& i : costs) cin >> i;
	ll m;
	cin >> m;
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v; --u, --v;
		gr[u].push_back({ v, costs[v] });
		gr[v].push_back({ u, costs[u] });
	}
	vector<ll>d(n, INF);
	vector<ll>p(n, -1);
	set<pair<ll, ll>>st;
	d[0] = 0;
	st.insert({ d[0], 0 });
	while (!st.empty()) {
		ll v = st.begin()->second;
		st.erase(st.begin());
		for (auto& e : gr[v]) {
			ll u = e.first, w = e.second;
			if (d[u] > d[v] + w) {
				st.erase({ d[u], u });
				d[u] = d[v] + w;
				p[u] = v;
				st.insert({ d[u], u });
			}
		}
	}
	if (d[n - 1] == INF) {
		cout << -1 << el;
		return 0;
	}
	vector<ll>ans;
	ll cur = n - 1;
	while (cur != 0) {
		ans.push_back(cur);
		cur = p[cur];
	}
	ans.push_back(0);
	reverse(all(ans));
	ll res = 0;
	ll canistra = 0;
	for (ll i = 0; i < ans.size() - 1; ++i) {
		if (canistra == 0) {
			if (costs[ans[i]] * 2 < costs[ans[i]] + costs[ans[i + 1]]) {
				res += costs[ans[i]] * 2;
				canistra = 1;
			}
			else {
				res += costs[ans[i]];
			}
		}
		else if (canistra == 1) {
			if (costs[ans[i]] > costs[ans[i + 1]] || i == ans.size()-2) {
				canistra = 0;
			}
			else {
				res += costs[ans[i]];
			}
		}
	}
	cout << res << el;
}
