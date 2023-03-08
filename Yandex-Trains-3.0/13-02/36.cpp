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

pair<ll, ll> convert(string s) {
	return { s[0] - 97, 56 - s[1] };
}

int main() {
	fastIO;
	ll n = 8;
	string s1, s2;
	cin >> s1 >> s2;
	ll x1 = convert(s1).first, y1 = convert(s1).second, x2 = convert(s2).first, y2 = convert(s2).second;
	queue<pair<ll, ll>> q;
	q.push({ x1, y1 });
	vector<pair<ll, ll>> dir = { {1,2}, {1,2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1} };
	vector<vector<ll>> d(n, vector<ll>(n, -1));
	vector<vector<pair<ll, ll>>> path(n, vector<pair<ll, ll>>(n, make_pair(-1, -1)));
	d[x1][y1] = 0;
	while (!q.empty()) {
		pair<ll, ll> u = q.front();
		q.pop();
		for (auto v : dir) {
			ll x = u.first + v.first, y = u.second + v.second;
			if (x >= 0 && x < n && y >= 0 && y < n && d[x][y] < 0) {
				d[x][y] = d[u.first][u.second] + 1;
				path[x][y] = { u.first, u.second };
				q.push({ u.first + v.first, u.second + v.second });
			}
		}
	}
	if (d[x2][y2] == -1) {
		cout << -1 << el;
		return 0;
	}
	if (d[x2][y2] % 2 == 0) {
		cout << d[x2][y2] / 2 << el;
	}
	else {
		cout << -1 << el;
	}
}
