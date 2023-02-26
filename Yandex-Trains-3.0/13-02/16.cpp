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
	ll n, k;
	cin >> n >> k;
	vector<ll>a(n + 2);
	a[0] = -INF, a[n + 1] = -INF;
	for (ll i = 1; i <= n; ++i){
		cin >> a[i];
	}
	vector<ll>ans(n + 2, 0);
	stack<ll>st;
	st.push(0);
	for (ll i = 1; i <= n + 1; ++i) {
		while (!st.empty() && a[st.top()] > a[i]) {
			ans[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	ll imin = 1;
	for (ll i = 1; i < n - k + 2; ++i) {
		if (imin < i) {
			imin = i;
		}
		while (ans[imin] < i + k) {
			imin = ans[imin];
		}
		cout << a[imin] << el;
	}
}
