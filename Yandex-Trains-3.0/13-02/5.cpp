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
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (ll& i : a) cin >> i;
	ll ans = 0;
	for (ll i = 1; i < n; ++i) {
		ans += min(a[i], a[i - 1]);
	}
	cout << ans << el;
}
