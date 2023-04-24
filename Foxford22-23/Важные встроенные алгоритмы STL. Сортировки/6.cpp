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

ll mrg(vector<ll>& a, ll& l, ll& m, ll& r) {
	ll it1 = 0, it2 = 0;
	ll cnt = 0;
	vector<ll>res(r - l);
	while (l + it1 < m && m + it2 < r) {
		if (a[l + it1] <= a[m + it2]) {
			res[it1 + it2] = a[l + it1];
			++it1;
		}
		else {
			res[it1 + it2] = a[m + it2];
			cnt += (m - l - it1);
			++it2;
		}
	}
	while (l + it1 < m) {
		res[it1 + it2] = a[l + it1];
		++it1;
	}
	while (m + it2 < r) {
		res[it1 + it2] = a[m + it2];
		++it2;
	}
	for (ll i = 0; i < it1 + it2; ++i) {
		a[l + i] = res[i];
	}
	return cnt;
}

ll mSort(vector<ll>& a, ll l, ll r) {
	if (l + 1 >= r) return 0;
	ll cnt = 0;
	ll m = (l + r) / 2;
	cnt += mSort(a, l, m);
	cnt += mSort(a, m, r);  
	cnt += mrg(a, l, m, r);
	return cnt;
}

int main() {
	fastIO;
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (ll& i : a) cin >> i;
	cout << mSort(a, 0, n) << el;
}
