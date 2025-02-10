#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int X; cin>>X;
  int ans=0;
  for(int i=1;i<10;++i) for(int j=1;j<10;++j)
    ans+=(i*j==X?0:i*j);
  cout<<ans<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t=1;
  // cin>>t;
  for(int i=1;i<=t;++i){
    //cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}

