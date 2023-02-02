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
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>a(n, vector<ll>(m));
	vector<pair<ll,ll>>ones;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 1) ones.push_back({i,j});
		}
	}
	vector<vector<ll>> ans(n, vector<ll>(m));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			ans[i][j] = INF;
			for (auto x : ones) {
				ans[i][j] = min(ans[i][j], abs(i-x.first) + abs(j-x.second));
			}
		}
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << el;
	}
}
