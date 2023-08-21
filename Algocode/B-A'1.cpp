#define _CRT_SECURE_NO_WARNINGS

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
#include <sstream>
#include <unordered_map>
//#include <intrin.h>

using namespace std;

#define el '\n'
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e14;

ll MOD;

void op(ll& a) {
	a = a % (ll)__builtin_popcount(a);
}

ll binpow(ll n) {
	if (n == 0) return 1;
	if (n % 2 == 1) return (binpow(n - 1) * 2) % MOD;
	else {
		ll b = binpow(n / 2) % MOD;
		return (b * b) % MOD;
	}
}

void inv(string& s, ll i, ll& num) {
	if (s[i] == '1') {
		--MOD;
		num -= binpow((ll)s.size() - i - 1) % MOD;
		num %= MOD;
		++MOD;
	}
	else {
		++MOD;
		num += binpow((ll)s.size() - i - 1) % MOD;
		num %= MOD;
		--MOD;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fastIO;
	ll n; cin >> n;
	string s; cin >> s;
	ll numAdd = 0;
	MOD = count(all(s), '1') + 1;
	for (ll i = 0; i < (ll)s.size(); ++i) {
		if (s[i] == '1') numAdd += (binpow((ll)s.size() - i - 1)) % MOD;
	}
	if (MOD == 2) {
		--MOD;
		for (ll i = 0; i < n; ++i) {
			if (s[i] == '1') {
				cout << 0 << el;
			}
			else {
				ll x = numAdd;
				inv(s, i, x);
				ll cnt = 1;
				while (x != 0) {
					++cnt;
					op(x);
				}
				cout << cnt << el;
			}
		}
		return 0;
	}
	ll numDel = 0;
	MOD = count(all(s), '1') - 1;
	for (ll i = 0; i < (ll)s.size(); ++i) {
		if (s[i] == '1') numDel += (binpow((ll)s.size() - i - 1)) % MOD;
	}
	++MOD;
	for (ll i = 0; i < n; ++i) {
		ll x;
		if (s[i] == '1') x = numDel;
		else x = numAdd;
		inv(s, i, x);
		ll cnt = 1;
		while (x != 0) {
			++cnt;
			op(x);
		}
		cout << cnt << el;
	}
}
