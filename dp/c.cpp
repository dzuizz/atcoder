#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n][3];

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> a[i][j];
        }
    }

    int dp[n][3];
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for (int i=1; i<n; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + a[i][j];
        }
    }

    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << '\n';
}