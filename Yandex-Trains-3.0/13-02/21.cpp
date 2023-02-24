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
const ll SIZE = 1e6+6;

int main() {
	fastIO;
	ll n;
	cin >> n;
	vector<ll>dp(SIZE, INF);
	dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
	vector<ll>c;
	for (ll i = 1; i <= 100; ++i) {
		c.push_back(i * i * i);
	}
	for (ll i = 4; i <= n; ++i) {
		for (ll j = 0; j < 100; ++j) {
			if (c[j] <= i && dp[i-c[j]] != INF) {
				dp[i] = min(dp[i - c[j]] + 1, dp[i]);
			}
		}
	}
	cout << dp[n] << el;
} 
