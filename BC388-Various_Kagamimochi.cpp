#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  int A[N],ans=0;
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=0,p=0;i<N;++i){
    while(p<N&&A[p]*2<=A[i]) ++p;
    ans+=p;
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

