#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int u[m],v[m];
  for(int i=0;i<m;++i) cin>>u[i]>>v[i],--u[i],--v[i];
  int ans=INT64_MAX;
  for(int msk=0;msk<(1<<n);++msk){
    int res=0;
    for(int i=0;i<m;++i){
      int cu=(msk>>u[i])&1;
      int cv=(msk>>v[i])&1;
      res+=cu==cv;
    }
    ans=min(ans,res);
  }
  cout<<ans<<'\n';
  return 0;
}

