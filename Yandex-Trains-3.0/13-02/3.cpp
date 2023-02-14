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
	fastIO;
	ll n;
	cin >> n;
	vector<ll>a(n);
	set<ll>s;
	for (ll& i : a) cin >> i;
	for (ll i : a) s.insert(i);
	a = {};
	for (auto i : s) a.push_back(i);
	ll m;
	cin >> m;
	while (m--) {
		ll t;
		cin >> t;
		cout << lower_bound(all(a), t) - a.begin() << el;
	}
}
