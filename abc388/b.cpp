#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,D; cin>>N>>D;
  int T[N],L[N];
  for(int i=0;i<N;++i) cin>>T[i]>>L[i];
  for(int k=1;k<=D;++k){
    int x=0;
    for(int i=0;i<N;++i)
      x=max(x,T[i]*(L[i]+k));
    cout<<x<<'\n';
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

