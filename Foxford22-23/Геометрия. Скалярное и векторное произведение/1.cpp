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

struct Point {
	ll x, y;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
};

inline Point operator - (const Point& a, const Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}

inline ld len(const Point& a) {
	return hypot(a.x, a.y);
}

inline ll dP(const Point& a, const Point& b) {
	return a.x * b.x + a.y * b.y;
}

inline ll cP(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}

istream& operator >> (istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

inline ld angle(Point& a, Point& b) {
	return atan2(cP(a, b), dP(a, b));
}

inline bool operator == (const Point& a, const Point& b) {
	return (a.x == b.x && a.y == b.y);
}

int main() {
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Point a(x2 - x1, y2 - y1);
	cout.precision(20);
	cout << len(a) << el;
}
