#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  int H[N];
  for(auto&x:H) cin>>x;
  int ans=1;
  for(int k=1;k<N;++k){
    vector<int> v[k];
    for(int i=0;i<N;++i)
      v[i%k].emplace_back(H[i]);
    for(int j=0;j<k;++j){
      int run=0,cur=0;
      for(int i=0;i<(int)v[j].size();++i){
        if(v[j][i]!=cur) run=1,cur=v[j][i];
        else ++run;
        ans=max(ans,run);
      }
    }
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

