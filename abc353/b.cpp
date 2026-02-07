#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k; cin >> n >> k;
    int x = k, ans = 1;

    for (int i = 0; i < n; ++i) {
        int e; cin >> e;

        if (e > x) ++ans, x = k;
        x -= e;
    }
    cout << ans << '\n';
}
