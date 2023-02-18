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
	ll n;
	cin >> n;
	stack<pair<ll, ll>>st;
	st.push({ 0, -1 });
	ll ans = 0;
	for (ll i = 1; i <= n+1; ++i) {
		ll h = 0, pos = i;
		if (i <= n) cin >> h;
		while (h < st.top().second) {
			pos = st.top().first;
			ans = max(ans, (i - st.top().first) * st.top().second);
			st.pop();
		}
		st.push({ pos, h });
	}
	cout << ans << el;
}
