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

vector<vector<ll>>gr;
vector<ll>colors;
vector<ll>topSort;

void dfs(ll u) {
	colors[u] = 1;
	for (auto v : gr[u]) {
		if (colors[v] == 0) dfs(v);
	}
	colors[u] = 2;
	topSort.push_back(u);
}

int main() {
	fastIO;
	ll n;
	cin >> n;
	gr.resize(n);
	colors.resize(n);
	vector<ll>a(n);
	for (ll& i : a) cin >> i;
	for (ll i = 0; i < n; ++i) {
		ll m;
		cin >> m;
		for (ll j = 0; j < m; ++j) {
			ll x;
			cin >> x; --x;
			gr[i].push_back(x);
		}
	}
	dfs(0);
	ll res = 0;
	for (ll i = 0; i < topSort.size(); ++i) {
		res += a[topSort[i]];
	}
	cout << res << " " << topSort.size() << el;
	for (ll& i : topSort) cout << i+1 << " ";
	cout << el;
}
