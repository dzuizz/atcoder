#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;

  bool f[4]{};
  string d="NESW";
  for(auto&c:s)
    for(int i:{0,1,2,3})
      if(c==d[i]) f[i]=1;
  cout<<(f[0]==f[2] && f[1]==f[3]? "Yes\n":"No\n");
  return 0;
}
