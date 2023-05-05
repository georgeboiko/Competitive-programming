#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef long double ld;

const ll p = 19, MOD = 9e9 + 7, SIZE = 1e5 + 5;
ll powers[SIZE];
string a, b;
vector<ll>h1, h2;

vector<ll> getHash(const string& s) {
	vector<ll>h(s.size());
	h[0] = s[0];
	for (ll i = 1; i < s.size(); ++i) h[i] = (h[i - 1] * p + s[i]) % MOD;
	return h;
}

inline ll subHash(ll l, ll r, const vector<ll>& h) {
	ll R = h[r], L = 0;
	if (l > 0) L = (h[l - 1] * powers[r - l + 1]) % MOD;
	return (R - L > 0 ? R - L + MOD : R - L);
}

bool f(ll len) {
	set<ll>x, y;
	map<ll, ll>mp1, mp2;
	for (ll i = 0; i + len <= (ll)a.size(); ++i) {
		x.insert(subHash(i, i + len - 1, h1));
		mp1[subHash(i, i + len - 1, h1)] = i;
	}
	for (ll i = 0; i + len <= (ll)b.size(); ++i) {
		y.insert(subHash(i, i + len - 1, h2));
		mp2[subHash(i, i + len - 1, h2)] = i;
	}
	for (auto& i : x) {
		if (y.find(i) != y.end()) {
			bool f = true;
			for (ll j = 0; j < len; ++j) {
				if (a[mp1[i] + j] != b[mp2[i] + j]) f = false;
			}
			if (f) return true;
		}
	}
	return false;
}

int main() {
	fastIO;
	powers[0] = 1;
	for (ll i = 1; i < SIZE; ++i) powers[i] = (powers[i - 1] * p) % MOD;
	cin >> a >> b;
	h1 = getHash(a), h2 = getHash(b);
	ll l = 0, r = min(a.size(), b.size())+1;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (f(m)) l = m;
		else r = m;
	}
	cout << l << el;
}
