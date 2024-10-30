#include<iostream>
using namespace std;
typedef long long ll;

const ll M = 998244353;

ll mul(ll a, ll b) {
    a %= M; b %= M;
    return (a*b)%M;
}

ll expo(ll a, ll b) {
    if (b == 0) return 1;
    ll res = expo(a, b/2);
    res = mul(res, res);
    if (b%2) res = mul(res, a);
    return res;
}

ll inv(ll x) {
    return expo(x, M-2);
}

int main() {
    ll n, A, B, k; cin >> n >> A >> B >> k;
    
    ll f[n+2]; f[0] = 1;
    for (ll i=1; i<=n; i++)
        f[i] = mul(f[i-1], i);
    
    ll ans = 0;
    for (ll a=0; a<=n; a++) {
        if (a*A > k) break;
        if ((k - a*A)%B > 0) continue;
        
        ll b = (k - a*A)/B;
        if (b > n) continue;
        
        ll nCa = mul(f[n], mul(inv(f[a]), inv(f[n-a])));
        ll nCb = mul(f[n], mul(inv(f[b]), inv(f[n-b])));
        ans += mul(nCa, nCb);
        ans %= M;
    }
    
    cout << ans << '\n';
}
