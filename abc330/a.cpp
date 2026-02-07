#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, e; cin >> n >> e;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        ans += (x >= e);
    }
    cout << ans << '\n';
}