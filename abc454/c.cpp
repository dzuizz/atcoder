#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  bool f[n]{}; f[0]=1;
  int cnt=1;
  vector<int> g[n];
  for(int i=0;i<m;++i){
    int a,b; cin>>a>>b; --a,--b;
    g[a].emplace_back(b);
  }
  queue<int> q; q.emplace(0);
  while(q.size()){
    int i=q.front(); q.pop();
    for(auto&x:g[i]) if(!f[x]){
      f[x]=1,++cnt;
      q.emplace(x);
    }
  }
  cout<<cnt<<'\n';
  return 0;
}
