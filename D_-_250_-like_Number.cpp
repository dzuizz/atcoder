#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> primes;
const ll M = 1e6;
bool prime[M+2];
ll ans, n;

int main() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (ll i = 2; i <= M; i++) {
        if (!prime[i]) continue;
        for (ll j = i*i; j <= M; j += i) prime[j] = 0;
    }
    for (ll i = 2; i <= M; i++) {
        if (prime[i]) primes.push_back(i);
    }

    cin >> n;
    for (int i = 0; i < primes.size(); i++) {
        ll res = 0, ind = i+1;
        while (ind < primes.size() && primes[ind] * primes[ind] * primes[ind] * primes[i] <= n) {
            ind++, res++;
        }
        if (res == 0) break;
        // cout << ">> " << primes[i] << ' ' << primes[ind] << endl;
        ans += res;
    }
    cout << ans << endl;
}