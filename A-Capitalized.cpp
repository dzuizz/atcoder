#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    bool flag = (s[0] < 'a');
    for (int i = 1; i < (int)s.size(); ++i) flag = flag && (s[i] >= 'a');
    cout << (flag ? "Yes\n" : "No\n");
}