#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, g, m, a=0, b=0, c; cin >> k >> g >> m;
    while (k--) {
        if (a == g) a = 0;
        else if (b == 0) b = m;
        else c = min(g, a+b), b = max(b-g+a, 0), a = c;
    }
    cout << a << " " << b << '\n';
}