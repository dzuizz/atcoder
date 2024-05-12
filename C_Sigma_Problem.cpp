#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int N; cin >> N;
    int a[N];

    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a, a + N);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x = N - (lower_bound(a + i + 1, a + N, (int)1e8 - a[i]) - a);
        ans += a[i] * (N-1) - x * (int)1e8;
    }

    cout << ans << '\n';
}
