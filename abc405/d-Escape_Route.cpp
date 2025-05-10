#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> d[4]={{0,1},{1,0},{0,-1},{-1,0}};
string s="<^>v";
void solve(){
  int h,w; cin>>h>>w;
  char g[h][w];
  queue<pair<int,int>> q;
  for(int i=0;i<h;++i) for(int j=0;j<w;++j){
    cin>>g[i][j];
    if(g[i][j]=='E')
      q.emplace(i,j);
  }
  while(q.size()){
    auto [i,j]=q.front(); q.pop();
    for(int k=0;k<4;++k){
      int ni=i+d[k].first,nj=j+d[k].second;
      if(ni>=0&&ni<h&&nj>=0&&nj<w&&g[ni][nj]=='.'){
        g[ni][nj]=s[k];
        q.emplace(ni,nj);
      }
    }
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j) cout<<g[i][j];
    cout<<'\n';
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

