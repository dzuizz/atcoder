#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  cout<<"Of"<<(char)tolower(s[0]);
  for(int i=1;i<(int)s.size();++i)
    cout<<s[i];
  cout<<'\n';
  return 0;
}

