#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int n; cin>>n;
  int ans=0;
  for(int i=0;i<n;++i){
    int a,b; cin>>a>>b;
    ans+=(a<b);
  }
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

