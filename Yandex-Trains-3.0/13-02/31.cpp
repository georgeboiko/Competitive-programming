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

vector<vector<ll>> g;
vector<ll> colors, tin, tout;
ll t = 0;
set<ll>s;

void dfs(ll u) {
    s.insert(u);
    colors[u] = 1;
    tin[u] = t++;
    for (auto v : g[u]) {
        if (colors[v] == 0) {
            s.insert(v);
            dfs(v);
        }
    }
    colors[u] = 2;
    tout[u] = t++;
}

int main() {
	fastIO;
    ll n;
    cin >> n;
    g.resize(n * n);
    colors.resize(n * n);
    tin.resize(n * n);
    tout.resize(n * n);
    vector<vector<ll>>a(n, vector<ll>(n));
    vector<vector<ll>>nums(n, vector<ll>(n)); ll pnt = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            char c; cin >> c;
            if (c == '.') {
                a[i][j] = 1;
            }
            nums[i][j] = pnt++;
        }
    }
    ll p1, p2;
    cin >> p1 >> p2; --p1, --p2;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                if (i >= 1 && a[i - 1][j] == 1) {
                    g[nums[i][j]].push_back(nums[i - 1][j]);
                    g[nums[i - 1][j]].push_back(nums[i][j]);
                }
                if (i + 1 < n && a[i + 1][j] == 1) {
                    g[nums[i + 1][j]].push_back(nums[i][j]);
                    g[nums[i][j]].push_back(nums[i + 1][j]);
                }
                if (j + 1 < n && a[i][j + 1] == 1) {
                    g[nums[i][j]].push_back(nums[i][j + 1]);
                    g[nums[i][j + 1]].push_back(nums[i][j]);
                }
                if (j >= 1 && a[i][j - 1] == 1) {
                    g[nums[i][j - 1]].push_back(nums[i][j]);
                    g[nums[i][j]].push_back(nums[i][j - 1]);
                }
            }
        }
    }
    vector<set<ll>> comps;
    for (ll i = 0; i < n * n; ++i) {
        if (colors[i] == 0) {
            dfs(i);
            comps.push_back(s);
            s.clear();
        }
    }
    for (auto x : comps) {
        for (auto i : x) {
            if (i == nums[p1][p2]) {
                cout << x.size() << el;
                return 0;
            }
        }
    }
}
