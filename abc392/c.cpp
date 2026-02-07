#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  int P[N]; for(int i=0;i<N;++i) cin>>P[i];
  int Q[N]; for(int i=0;i<N;++i) cin>>Q[i];
  int A[N]; for(int i=0;i<N;++i) A[Q[i]-1]=Q[P[i]-1];
  for(auto&x:A)cout<<x<<" ";
  cout<<'\n';
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

