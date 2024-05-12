#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;

    int x = 0;
    for (int i = 0; i < n; ++i) {
        int e; cin >> e;

        if (!x) x = e;
        else if (e > x) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}