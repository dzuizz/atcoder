#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,M; cin>>N>>M;
  map<int,vector<pair<int,bool>>>mp;
  for(int i=0;i<M;++i){
    int x,y;
    char c;
    cin>>x>>y>>c;
    mp[x].emplace_back(y,c=='B');
  }
  int w=N+1;
  for(auto&[x,v]:mp){
    int b=0;
    for(auto&[y,c]:v){
      if(c) b=max(b,y);
      else w=min(w,y);
    }
    if(b>=w){
      cout<<"No\n";
      return;
    }
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

