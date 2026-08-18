#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs(vector<int>(&g)[], int u,int p){
  int ret=1;
  for(auto&v:g[u]) if(v!=p)
    ret += dfs(g,v,u);
  return ret;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  vector<int> g[n+1];
  for(int i=0;i<n-1;++i){
    int u,v; cin>>u>>v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  int summ=0,maxi=0;
  for(auto&v:g[1]){
    int sub = dfs(g,v,1);
    maxi = max(maxi,sub),
    summ += sub;
  }
  cout<< summ-maxi+1 <<'\n';
  return 0;
}
