#include <bits/stdc++.h>
using namespace std;

int n, s, m, l;

int f(int n) {
    if (n <= 0) return 0;
    return min({f(n-6)+s,f(n-8)+m,f(n-12)+l});
}

int main() {
    cin >> n >> s >> m >> l;
    cout << f(n) << '\n';
}