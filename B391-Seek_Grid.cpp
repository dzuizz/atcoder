#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,M; cin>>N>>M;
  string S[N],T[M];
  for(int i=0;i<N;++i) cin>>S[i];
  for(int j=0;j<M;++j) cin>>T[j];
  for(int a=0;a<=N-M;++a) for(int b=0;b<=N-M;++b) {
    bool flag=true;
    for(int i=0;i<M;++i) for(int j=0;j<M;++j) if(S[i+a][j+b]!=T[i][j])
      flag=false;
    if(flag){
      cout<<a+1<<" "<<b+1<<'\n';
      return;
    }
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

