#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, i;
vector<int> v;
map<int, int> mp;
vector<pair<int, int>> p;

signed main() {
    cin >> n;
    v.resize(n); p.resize(n+1);
    p[n].first = INT64_MAX;

    for (i=0; i<n; i++) cin >> v[i], p[i].first = v[i];
    sort(p.begin(), p.end());
    mp[p[i].first] = 0;
    for (int i=n-1; i>=0; i--) p[i].second = p[i+1].second + p[i].first, mp[p[i].first] = p[i].second;

    for (auto &x : v) {
        cout << mp.upper_bound(x)->second << " ";
    }
}