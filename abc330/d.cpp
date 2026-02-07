#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;
    string a[n];

    for (int i=0; i<n; i++) cin >> a[i];

    int cnt[n][2]; memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]=='x') continue;
            ++cnt[i][0], ++cnt[j][1];
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]=='x') continue;
            ans += (cnt[i][0]-1)*(cnt[j][1]-1);
        }
    }

    cout << ans << '\n';
}