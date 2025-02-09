#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,M; cin>>N>>M;
  bool a[N]; memset(a,0,sizeof a);
  for(int i=0;i<M;++i){
    int e; cin>>e;
    a[--e]=1;
  }
  vector<int>v;
  for(int i=0;i<N;++i) if(!a[i])
    v.emplace_back(i+1);
  cout<<(int)v.size()<<'\n';
  for(auto&x:v) cout<<x<<" ";
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

