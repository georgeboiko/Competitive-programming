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
	vector<ll>a(n);
	for (ll& i : a) cin >> i;
	vector<ll>dp(n, 0), p(n, -1);
	dp[0] = 1;
	for (ll i = 1; i < n; ++i) {
		dp[i] = 1;
		for (ll j = 0; j < n; ++j) {
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
	}
	ll maxx = *max_element(all(dp));
	ll cur = -1;
	for (ll i = 0; i < n; ++i) {
		if (dp[i] == maxx) {
			cur = i;
		}
	}
	vector<ll>ans;
	while (cur != -1) {
		ans.push_back(a[cur]);
		cur = p[cur];
	}
	reverse(all(ans));
	for (ll& i : ans) cout << i << " ";
	cout << el;
} 
