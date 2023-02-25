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

struct part {
	ll l, r, used;
	part() {}
	part(ll l, ll r, ll used) : l(l), r(r), used(used) {}
};

bool collide(ll l1, ll r1, ll l2, ll r2) {
	return !(r1 < l2 || r2 < l1);
}

int main() {
	fastIO;
	ll m, n;
	cin >> m >> n;
	vector<part>a;
	for (ll i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		a.push_back(part(l,r,0));
		for (ll j = 0; j < i; ++j) {
			if (collide(a[j].l, a[j].r, l, r)) {
				a[j].used = 1;
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		ans += !(a[i].used);
	}
	cout << ans << el;
}
