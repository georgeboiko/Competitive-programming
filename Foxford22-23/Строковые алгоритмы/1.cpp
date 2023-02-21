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

const ll p = 179, Mod = 2e9 + 11;
const ll SIZE = 1e5 + 5;
ll powers[SIZE];

vector<ll>getHash(const string& s) {
	ll n = s.size();
	vector<ll>h(n);
	h[0] = s[0];
	for (ll i = 1; i < n; ++i) {
		h[i] = (h[i - 1] * p + s[i]) % Mod;
	}
	return h;
}

inline ll subHash(ll l, ll r, const vector<ll>& h) {
	ll R = h[r];
	ll L = 0;
	if (l > 0) L = (h[l - 1] * powers[r - l + 1]) % Mod;
	return (R - L < 0 ? R - L + Mod : R - L);
}

int main() {
	powers[0] = 1;
	for (ll i = 1; i < SIZE; ++i) {
		powers[i] = (powers[i - 1] * p) % Mod;
	}
	string s;
	cin >> s;
	vector<ll>h = getHash(s);
	ll m;
	cin >> m;
	while (m--) {
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		--l1, --r1, --l2, --r2;
		if (subHash(l1, r1, h) == subHash(l2, r2, h)) cout << '+';
		else cout << '-';
	}
	cout << el;
} 
