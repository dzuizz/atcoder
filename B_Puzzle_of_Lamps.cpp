#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, cnt, cur = 1;
string s, ans = "";

signed main() {
    cin >> n >> s;

    for (int i = n; i > 0; --i) {
        if (s[i-1] - '0' == cur) {
            cnt += i, cur = 1 - cur;
            for (int j = 0; j < i; ++j) ans += ('A' + cur);
        }
    }

    cout << cnt << '\n' << ans << '\n';
}
