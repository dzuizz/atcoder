#include <bits/stdc++.h>
using namespace std;

int n, s, k, i, p, q, sum;

int main() {
    cin >> n >> s >> k;

    for (i=0; i<n; i++) {
        cin >> p >> q;
        sum += p*q;
    }
    
    cout << sum+(sum<s?k:0) << '\n';
}