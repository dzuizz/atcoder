#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n; cin>>n;
  int l[2*n]; for(auto&x:l) cin>>x;

  sort(l,l+2*n);
  int ans=0;
  for(int i=0;i<2*n;i+=2) ans+=l[i];
  cout<<ans<<'\n';
  return 0;
}
