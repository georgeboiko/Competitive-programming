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
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(p), r(p, p);
    for (auto& x : a) cin >> x;
    vector<pair<ll, ll>> tmp(p);
    for (ll i = 0; i < p; i++) tmp[i] = { a[i], i };
    sort(all(tmp));
    for (ll i = 0; i < p - 1; i++) {
        if (tmp[i].first == tmp[i + 1].first) {
            r[tmp[i].second] = tmp[i + 1].second;
        }
    }
    priority_queue<pair<ll, ll>> q;
    vector<bool> usedNow(n + 1);
    ll cnt = 0, i = 0;
    while (cnt < k && i < p) {
        if (!usedNow[a[i]]) ++cnt;
        q.push({ r[i], i });
        usedNow[a[i]] = 1;
        ++i;
    }
    while (i < p) {
        if (!usedNow[a[i]]) {
            ++cnt;
            usedNow[a[q.top().second]] = 0;
            q.pop();
        }
        usedNow[a[i]] = 1;
        q.push({ r[i], i });
        ++i;
    }
    cout << cnt << el;
}
