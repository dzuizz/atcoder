#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    if (s[0] != s[1] && s[0] != s[2]) cout << s[0] << '\n';
    else if (s[1] != s[0] && s[1] != s[2]) cout << s[1] << '\n';
    else if (s[2] != s[0] && s[2] != s[1]) cout << s[2] << '\n';
    else cout << "-1\n";
}