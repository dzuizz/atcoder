// ABC 363

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  string s; cin >> s;
  sort(s.begin(), s.end());
  map<string, bool> mp;
  do {
    bool flag=true;
    for (int i=0; i<=N-K&&flag; ++i) {
      string tmp="", pmt;
      for (int j=i; j<i+K; ++j) tmp += s[j];
      pmt=tmp;
      reverse(pmt.begin(),pmt.end());
      if (tmp==pmt) flag=false;
    }
    if (flag) mp[s]=true;
  } while (next_permutation(s.begin(), s.end()));
  cout << mp.size() << '\n';
}

