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

void solve() {
	ll n;
	cin >> n;
	vector<ld>a(n), srt;
	for (ld& i : a) cin >> i;
	srt = a;
	sort(all(srt));
	stack<ld>st;
	ll ind = 0;
	vector<ld>b;
	for (ll i = 0; i < n; ++i) {
		if (a[i] == srt[ind]) {
			++ind;
			b.push_back(a[i]);
		}
		else if (st.size() != 0 && st.top() == srt[ind]) {
			++ind;
			--i;
			b.push_back(st.top());
			st.pop();
		}
		else {
			st.push(a[i]);
		}
	}
	//reverse(all(b));
	while (!st.empty()) {
		b.push_back(st.top());
		st.pop();
	}
	if (b == srt) cout << 1 << el;
	else cout << 0 << el;
}

int main() {
	ll t;
	cin >> t;
	while (t--) solve();
}
