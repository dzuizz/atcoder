#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  for(int i=0;i<(int)s.size();++i) if(i!=(int)s.size()/2) cout<<s[i];
  cout<<'\n';
  return 0;
}

