#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

signed main() {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0, mul = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans = ((ans + (a[i]%MOD * i)%MOD)%MOD + (a[i]%MOD * mul)%MOD)%MOD;

        int x = a[i], add = 1;
        while (x) add *= 10, x /= 10;
        mul = (mul + add%MOD)%MOD;
    }

    cout << ans << '\n';
}