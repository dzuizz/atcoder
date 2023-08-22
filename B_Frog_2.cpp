#include<iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int a[n];

    for (int i=0; i<n; i++) cin >> a[i];

    int dp[n]; dp[0] = 0;

    for (int i=1; i<n; i++) {
        dp[i] = dp[i-1]+abs(a[i]-a[i-1]);
        for (int j=max(0, i-k); j<i-1; j++) {
            dp[i] = min(dp[i], dp[j]+abs(a[i]-a[j]));
        }
    }

    cout << dp[n-1] << '\n';
}