#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,run=0,p=0; cin>>N;
  for(int i=0;i<N;++i){
    int T,V; cin>>T>>V;
    run=max(run-T+p,0ll),p=T;
    run+=V;
  }
  cout<<run<<'\n';
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

