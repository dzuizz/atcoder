#include<iostream>
using namespace std;

#define int long long

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

signed main() {
    int n, x, y; cin >> n >> x >> y;
    int p[n-1], t[n-1];
    int lcm=1;
    
    for (int i=0; i<n-1; i++) {
        cin >> p[i] >> t[i];
        
        lcm *= p[i]/gcd(lcm, p[i]);
    }

    int ans[lcm];
    for (int i=0; i<lcm; i++) {
        int cur=i;
        cur += x;

        for (int j=0; j<n-1; j++) {
            cur += (p[j]-(cur%p[j]))%p[j] + t[j];
        }

        ans[i] = cur+y;
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << x+ans[x%lcm] - x%lcm << '\n';
    }
}