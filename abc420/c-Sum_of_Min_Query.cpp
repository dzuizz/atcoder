#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int n,q; cin>>n>>q;
  int a[n]; for(auto&x:a) cin>>x;
  int b[n]; for(auto&x:b) cin>>x;
  int ans=0;
  for(int i=0;i<n;++i)
    ans+=min(a[i],b[i]);
  while(q--){
    char c; cin>>c;
    int x,v; cin>>x>>v; --x;
    ans-=min(a[x],b[x]);
    if(c=='A') a[x]=v;
    else b[x]=v;
    ans+=min(a[x],b[x]);
    cout<<ans<<'\n';
  }
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

