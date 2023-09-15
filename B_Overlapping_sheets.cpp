#include<iostream>
using namespace std;

const int MAX_N = 105;

int grid[MAX_N][MAX_N];

int main() {
    int n; cin >> n;
    
    for (int i=0; i<n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        for (int i=a; i<b; i++) {
            for (int j=c; j<d; j++) {
                grid[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i=0; i<MAX_N; i++) {
        for (int j=0; j<MAX_N; j++) {
            ans += grid[i][j];
        }
    }

    cout << ans << '\n';
}