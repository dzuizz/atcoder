#include<algorithm>
#include<iostream>
using namespace std;

#define int long long

signed main() {
    int n, d, p; cin >> n >> d >> p;
    int a[n];

    int ans=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    sort(a, a + n, greater<int>());
    
    int run=0;
    for (int i=0; i<n; i++) {
        run += a[i];

        if (i%d == d-1) {
            if (run > p) {
                ans += p - run;
            } else break;

            run = 0;
        }
    }

    if (run > p) ans += p - run;

    cout << ans << '\n';
}