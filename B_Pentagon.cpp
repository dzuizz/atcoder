#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int x = abs(a[0]-a[1]), y = abs(b[0]-b[1]);
    cout << (x==y||(5-x)==y?"Yes\n":"No\n");
}