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

int main() {
	fastIO;
	string s;
	getline(cin, s, '\0');
	map<char, ll>mp;
	for (auto& i : s) {
		if (i != ' ' && i != '\n') ++mp[i];
	}
	ll maxx = 0;
	for (auto& i : mp) maxx = max(maxx, i.second);
	vector<vector<char>>ans(maxx, vector<char>(mp.size()));
	ll cn = 0;
	for (auto& i : mp) {
		ll cnt = maxx-i.second;
		for (ll j = 0; j < maxx; ++j) {
			if (cnt > 0) {
				--cnt;
				ans[j][cn] = ' ';
			}
			else ans[j][cn] = '#';
		}
		++cn;
	}
	for (ll i = 0; i < maxx; ++i) {
		for (ll j = 0; j < mp.size(); ++j) {
			cout << ans[i][j];
		}
		cout << el;
	}
	for (auto& i : mp) cout << i.first;
	cout << el;
}
