#include<iostream>
using namespace std;

#define int long long

signed main() {
    int n, m, p; cin >> n >> m >> p;

    int ans = (n>=m?1:0) + (n-m)/p;

    cout << ans << '\n';
}