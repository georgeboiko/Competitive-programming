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
	ll k, n;
	cin >> k >> n;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
	priority_queue<ll, vector<ll>, greater<ll>> t;
	for (ll i = 1; i <= k; ++i) {
		t.push(i);
	}
	map<ll, ll>mp;
	for (ll i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		while (!q.empty() && q.top().first < a) {
			t.push(q.top().second);
			q.pop();
		}
		if (!t.empty() && q.size() < k) {
			q.push({ b, t.top()});
			mp[i + 1] = t.top();
			t.pop();
		}
		else {
			cout << 0 << " " << i + 1 << el;
			return 0;
		}
	}
	for (auto x : mp) {
		cout << x.second << el;
	}
}
