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

int main() {
	fastIO;
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	vector<vector<ll>> pref(n + 1, vector<ll>(m + 1));
	pref[0] = vector<ll>(m + 1, 0);
	for (ll i = 0; i <= n; ++i) pref[i][0] = 0;
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= m; ++j) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + a[i - 1][j - 1] - pref[i - 1][j - 1];
		}
	}
	while (k--) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2; --x1, --y1;
		cout << pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1] << el;
	}
}
