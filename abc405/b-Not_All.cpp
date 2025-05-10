#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,M; cin>>N>>M;
  int A[N],p[M];
  for(int i=0;i<N;++i) cin>>A[i];
  memset(p,0x3f,sizeof p);
  for(int i=N-1;i>=0;--i){
    p[--A[i]]=i;
  }
  cout<<max(N-*max_element(p,p+M),0ll)<<'\n';
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

