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
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	ll x = 2 * (a - 1) + b;
	ll f = x - k;
	ll s = x + k;
	ll r1 = (f + 1) / 2;
	ll r2 = (s + 1) / 2;
	if (f < 1 && s > n) {
		cout << -1 << el;
	}
	else if (s <= n && abs(r2 - a) <= abs(r1 - a)) {
		cout << r2 << " " << (s + 1) % 2 + 1 << el;
	}
	else {
		cout << r1 << " " << (f + 1) % 2 + 1 << el;
	}
}
