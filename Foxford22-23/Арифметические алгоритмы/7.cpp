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

ll gcdExt(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcdExt(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
	fastIO;
	ll a, b, c;
	cin >> a >> b >> c;
	ll x = 0, y = 0;
	ll gcd = gcdExt(a, b, x, y);
	if (c % gcd != 0) {
		cout << "Impossible\n";
		return 0;
	}
	cout << gcd << " " << c / gcd * x << " " << c / gcd * y << el;
}
