#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define fi first
#define se second

void round(ll &n, ll k) {
    ll a = (n / k) * k;
    ll b = a + k;
    
    n = (n - a >= b - n) ? b : a;
}

int main() {
    ll n, k; cin >> n >> k;

    ll cur = 10;
    for (int i = 0; i < k; i++) {
        round(n, cur);
        cur *= 10;
    }

    cout << n << '\n';
}
