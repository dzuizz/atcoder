#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  priority_queue<int>pq;
  pq.emplace(-3e18);
  for(int i=0;i<N/2;++i){
    int e; cin>>e;
    pq.emplace(-e);
  }
  int ans=0;
  for(int i=N/2;i<N;++i){
    int x; cin>>x;
    if(x>=2*-pq.top()){
      ++ans;
      pq.pop();
    }
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

