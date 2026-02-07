#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,R; cin>>N>>R;
  for(int i=0;i<N;++i){
    int D,A; cin>>D>>A;
    if(D==1&&1600<=R&&R<=2799||D==2&&1200<=R&&R<=2399) R+=A;
  }
  cout<<R<<'\n';
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

