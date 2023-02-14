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
	ld a, b, c;
	ll time1, time2, time3; char cmd;
	cin >> time1 >> cmd >> time2 >> cmd >> time3;
	a = time1 * 3600 + time2 * 60 + time3;
	cin >> time1 >> cmd >> time2 >> cmd >> time3;
	b = time1 * 3600 + time2 * 60 + time3;
	cin >> time1 >> cmd >> time2 >> cmd >> time3;
	c = time1 * 3600 + time2 * 60 + time3;
	if (c < a) c += 86400;
	ll ans = round((c - a) / 2) + b;
	time1 = ans / 3600; 
	time1 %= 24;
	time2 = (ans % 3600) / 60;
	time3 = (ans % 3600) % 60;
	if (time1 < 10) cout << 0;
	cout << time1 << ':';
	if (time2 < 10) cout << 0;
	cout << time2 << ':';
	if (time3 < 10) cout << 0;
	cout << time3 << el;
}
