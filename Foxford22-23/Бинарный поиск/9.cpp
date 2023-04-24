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

struct w {
	ll t, z, y;
};

ll m, n;
vector<w> a;

bool f(ll s) {
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll x = ((s + a[i].y) / (a[i].z * a[i].t + a[i].y));
		ans += x * a[i].z + max((s - a[i].z*a[i].t*x - a[i].y*x)/a[i].t, 0LL);
	}
	return (ans >= m);
}

int main() {
	fastIO;
	cin >> m >> n;
	for (ll i = 0; i < n; ++i) {
		w temp;
		cin >> temp.t >> temp.z >> temp.y;
		a.push_back(temp);
	}
	if (m == 0) {
		cout << "0\n";
		return 0;
	}
	ll l = 0, r = 1e9;
	while (r - l > 1) {
		ll M = (l + r) / 2;
		if (f(M)) r = M;
		else l = M;
	}
	cout << r << el;
}
