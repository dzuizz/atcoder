#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int a[2] = {0, 0}, ans = 0;

  for (auto &c : s) {
    if (c == 'T') a[0]++;
    else a[1]++;
    if (a[1-ans] > a[ans]) ans = 1-ans;
  }
  cout << (ans ? "A\n" : "T\n");
}
