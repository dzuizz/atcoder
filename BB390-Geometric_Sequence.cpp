#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,a,b,e; cin>>N>>a>>b;
  for(int i=2;i<N;++i){
    cin>>e;
    if(e*a!=b*b){
      cout<<"No\n";
      return;
    }
    a=b,b=e;
  }
  cout<<"Yes\n";
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

