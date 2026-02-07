#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a = 0, b = 0;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a += x, b += y;
    }

    cout << (a == b ? "Draw\n" : (a > b ? "Takahashi\n" : "Aoki\n"));
}
