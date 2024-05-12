#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, int> coins[6] = {
    make_pair(0, 1),
    make_pair(0, 5),
    make_pair(0, 10),
    make_pair(0, 50),
    make_pair(0, 100),
    make_pair(0, 500)
};
int n, e;

signed main() {
    for (int i = 0; i < 6; ++i) cin >> coins[i].first;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> e;

        for (int j = 5; j >= 0; --j) {
            int x = min(coins[j].first, e / coins[j].second);
            coins[j].first -= x, e -= x * coins[j].second;
        }

        if (e) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}