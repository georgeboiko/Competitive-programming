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
	ll n, s, f;
	cin >> n >> s >> f; --s, --f;
	vector<vector<pair<ll, ll>>>gr(n);
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			ll t;
			cin >> t;
			if (t != -1 && i != j) {
				gr[i].push_back({ j, t });
				//gr[j].push_back({ i, t });
			}
		}
	}
	vector<ll>d(n, INF);
	vector<ll>p(n, -1);
	set<pair<ll, ll>>st;
	d[s] = 0;
	st.insert({ d[s], s });
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
	if (d[f] == INF) {
		cout << -1 << el;
		return 0;
	}
	vector<ll>ans;
	ll cur = f;
	while (cur != s) {
		ans.push_back(cur);
		cur = p[cur];
	}
	ans.push_back(s);
	reverse(all(ans));
	for (ll i : ans) cout << i+1 << " ";
	cout << el;
}
