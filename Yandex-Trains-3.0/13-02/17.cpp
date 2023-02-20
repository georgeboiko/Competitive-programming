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
	ll n;
	cin >> n;
	deque<ll> l, r;
	while (n--) {
		char c;
		cin >> c;
		if (c == '+') {
			ll i;
			cin >> i;
			r.push_back(i);
		}
		if (c == '*') {
			ll i;
			cin >> i;
			r.push_front(i);
		}
		if (c == '-') {
			cout << l.front() << el;
			l.pop_front();
		}
		if (l.size() < r.size()) {
			l.push_back(r.front());
			r.pop_front();
		}
	}
} 
