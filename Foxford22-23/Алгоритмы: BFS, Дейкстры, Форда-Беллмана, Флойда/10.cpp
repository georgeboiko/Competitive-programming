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
	vector<vector<ld>>gr(n, vector<ld>(n));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			cin >> gr[i][j];
		}
	}
	for (ll k = 0; k < n; ++k) {
		for (ll i = 0; i < n; ++i) {
			for (ll j = 0; j < n; ++j) {
				gr[i][j] = max(gr[i][j], gr[i][k] * gr[k][j]);
			}
		}
	}
	for (ll i = 0; i < n; ++i) {
		if (gr[i][i] > 1) {
			cout << "YES" << el;
			return 0;
		}
	}
	cout << "NO" << el;
}
