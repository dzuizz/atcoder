#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int x = m, y = 0, ans = 0;
    for (auto &c : s) {
        if (c == '0') {
            x = m, y = ans;
        } else if (c == '1') {
            if (x) --x;
            else if (y) --y;
            else ans++;
        } else if (c == '2') {
            if (y) --y;
            else ans++;
        }
    }

    cout << ans << '\n';
}