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
const ll SIZE = 1e6+6;

int main() {
	fastIO;
	ll n;
	cin >> n;
	vector<ld>a(n);
	for (ld& i : a) cin >> i;
	sort(all(a));
	priority_queue<ld, vector<ld>, greater<ld>>q;
	ld ans = 0;
	for (ld& i : a) q.push(i);
	while (q.size() > 1) {
		ld x = 0, y = 0;
		if (!q.empty()) {
			x = q.top();
			q.pop();
		}
		if (!q.empty()) {
			y = q.top();
			q.pop();
		}
		ans += (x + y) * 0.05;
		q.push(x + y);
	}
	cout << fixed;
	cout.precision(2);
	cout << ans << el;
}
