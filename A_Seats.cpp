#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt=0;
  for (int i=1; i<n-1; ++i)
    if (s[i-1] == '#' && s[i] == '.' && s[i+1] == '#') ++cnt;
  cout << cnt << '\n';
}
