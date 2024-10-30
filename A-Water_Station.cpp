#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cout << (n%5 < 3 ? n - n%5 : n+5 - n%5) << '\n';
}