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
#include <deque>

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e14;

int main() {
	fastIO;
	string a, b;
	cin >> a >> b;
	vector<vector<ll>>dp(a.size() + 1, vector<ll>(b.size() + 1));
	dp[0][0] = 0;
	for (ll i = 1; i <= a.size(); ++i) {
		dp[i][0] = i;
	}
	for (ll i = 1; i <= b.size(); ++i) {
		dp[0][i] = i;
	}
	for (ll i = 1; i <= a.size(); ++i) {
		for (ll j = 1; j <= b.size(); ++j) {
			ll res = a[i - 1] == b[j - 1] ? 0 : 1;
			dp[i][j] = min(
				dp[i - 1][j] + 1,
				min(
					dp[i][j - 1] + 1,
					dp[i - 1][j - 1] + res
				)
			);
		}
	}
	cout << dp[a.size()][b.size()] << el;
}
