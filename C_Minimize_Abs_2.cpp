#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;

    int ans = INT64_MAX;
    for (int i=0; i*i<=n; ++i) {
        int x = n - i*i, y = sqrt(x);
        ans = min(ans, min(x-y*y, abs(x-(y+1)*(y+1))));
    }

    cout << ans << '\n';
}