#include<iostream>
using namespace std;

#define int long long

const int MAX_N = 20;
int n;

int adjlist[MAX_N][MAX_N];
bool vis[MAX_N];

int solve(int x) {
    if (x == n) return 0;
    int res=solve(x+1);

    if (vis[x]) return res;

    for (int i=x+1; i<n; i++) {
        if (vis[i]) continue;

        vis[i] = 1;
        res = max(res, solve(x+1) + adjlist[x][i]);
        vis[i] = 0;
    }

    return res;
}

signed main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x; cin >> x;
            adjlist[i][j] = x;
        }
    }

    cout << solve(0) << '\n';
}