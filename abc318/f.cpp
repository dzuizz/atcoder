#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

int n;
vector<int> l, x, v;

signed main(void) {
    cin >> n;

    int ans=0;

    for (int i=0; i<n; i++) {
        int e; cin >> e;
        x.push_back(e);
    }
    for (int i=0; i<n; i++) {
        int e; cin >> e;
        l.push_back(e);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            v.push_back(x[i] + l[j]);
            v.push_back(x[i] - l[j] - 1);
        }
    }
    sort(v.begin(), v.end());

    for (int i=1; i<v.size(); i++){
        bool flag = 1;
        int lf=-1, rg=0, nx;

        for (int j=0; j<n; j++){
            if (x[j] < v[i]) lf++, rg++;
            else break;
        }

        for (int j=0; j<n&&flag; j++){
            if (lf < 0) nx = rg, rg++;
            else if (rg >= n) nx = lf, lf--;
            else if (v[i]-x[lf] > x[rg]-v[i]) nx = rg, rg++;
            else nx = lf, lf--;
            if (abs(x[nx] - v[i]) > l[j]) flag = 0;
        }

        if (flag) ans += v[i]-v[i-1];
    }

    cout << ans << '\n';
    return 0;
}
