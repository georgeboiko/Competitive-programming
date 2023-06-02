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
const ld eps = 1e-8;
const ld PI = acos(-1.0);

struct Point {
	ld x, y;
	Point() {}
	Point(ld x, ld y) : x(x), y(y) {}
};

inline Point operator - (const Point& a, const Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}

inline ld len(const Point& a) {
	return hypot(a.x, a.y);
}

inline ld dP(const Point& a, const Point& b) {
	return a.x * b.x + a.y * b.y;
}

inline ld cP(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}

istream& operator >> (istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

inline ld angle(const Point& a, const Point& b) {
	return atan2(cP(a, b), dP(a, b));
}

inline bool operator == (const Point& a, const Point& b) {
	return (a.x == b.x && a.y == b.y);
}

inline bool pointOnRay(const Point& p, const Point& a, const Point& b) {
	return cP(p - a, b - a) == 0 && dP(p - a, b - a) >= 0;
}

inline bool pointOnSeg(const Point& p, const Point& a, const Point& b) {
	return pointOnRay(p, a, b) && pointOnRay(p, b, a);
}

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

int main() {
	Point a;
	cin >> a;
	cout.precision(20);
	ld res = angle(Point(1, 0), a);
	if (res < 0) res += 2 * PI;
	cout << res << el;
}
