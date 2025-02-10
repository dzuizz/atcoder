#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  int A[N+1],x=0; memset(A,0,sizeof A);
  for(int i=1;i<=N;++i){
    x-=A[i-1];
    int e; cin>>e; e+=x++;
    ++A[min(i+e,N)];
    cout<<max(e-N+i,0ll)<<" ";
  }
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

