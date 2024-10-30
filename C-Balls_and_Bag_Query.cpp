// ABC 366

#include <iostream>
#include <map>
using namespace std;

int main() {
  int Q; cin >> Q;
  map<int,int> mp;
  while (Q--) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x;
      ++mp[x];
    } else if (t == 2) {
      int x; cin >> x;
      --mp[x];
      if (!mp[x]) mp.erase(x);
    } else cout << mp.size() << '\n';
  }
}

