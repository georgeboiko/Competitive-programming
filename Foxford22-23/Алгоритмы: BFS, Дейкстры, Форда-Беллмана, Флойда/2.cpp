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

vector<ll>ans;

ll summ(ll x) {
	string s = to_string(x);
	ll ans = 0;
	for (ll i = 0; i < s.size(); ++i) {
		ans += s[i] - 48;
	}
	return ans;
}

int main() {
	fastIO;
	ll n = 10000;
	ll a, b;
	cin >> a >> b;
	queue<ll>q;
	ans.resize(n, -1);
	ans[a] = 0;
	q.push(a);
	while (!q.empty()) {
		ll v = q.front(); q.pop();
		if (v == b) break;
		if (v*3 >= 0 && v*3 < n && ans[v*3] == -1) {
			ans[v * 3] = ans[v] + 1;
			q.push(v * 3);
		}
		if (v + summ(v) >= 0 && v + summ(v) < n && ans[v+summ(v)] == -1) {
			ans[v + summ(v)] = ans[v] + 1;
			q.push(v + summ(v));
		}
		if (v - 2 >= 0 && v - 2 < n && ans[v-2] == -1) {
			ans[v - 2] = ans[v] + 1;
			q.push(v - 2);
		}
	}
	cout << ans[b] << el;
}
