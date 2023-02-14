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
	vector<pair<ll, ll>>a(n);
	for (auto& i : a) {
		cin >> i.first >> i.second;
	}
	ll minX = INF, maxX = -INF, minY = INF, maxY = -INF;
	for (auto& i : a) {
		minX = min(minX, i.first);
		maxX = max(maxX, i.first);
		minY = min(minY, i.second);
		maxY = max(maxY, i.second);
	}
	cout << minX << " " << minY << " " << maxX << " " << maxY << el;
}
