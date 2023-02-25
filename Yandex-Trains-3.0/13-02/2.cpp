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
	ll k;
	cin >> k;
	string s;
	cin >> s;
	set<char>st;
	ll ans = 0;
	for (char& i : s) st.insert(i);
	for (char x : st) {
		ll l = 0, r = 0, res = 0, cnt = 0;
		if (s[0] == x) ++res;
		for (ll i = 0; i < s.size(); ++i) {
			cnt = r - l + 1 - res;
			if (cnt <= k) {
				ans = max(ans, cnt+res);
				++r;
				if (s[r] == x) ++res;
			}
			else {
				++l, ++r;
				if (s[l - 1] == x) --res;
				if (s[r] == x) ++res;
			}
		}
	}
	cout << ans << el;
}
