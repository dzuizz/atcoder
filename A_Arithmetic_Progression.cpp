#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, d; cin >> a >> b >> d;

    cout << a;
    for (int i = a + d; i <= b; i += d) cout << " " << i;
    cout << '\n';
}