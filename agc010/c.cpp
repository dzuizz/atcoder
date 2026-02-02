#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=1e5+5;
vector<int> adj[N];
bool ans=1;
int a[N];
int dfs(int u,int p){
  int sc=0,cnt=0,mx=0;
  for(auto&v:adj[u]) if(v!=p){
    int x=dfs(v,u);
    sc+=x,++cnt,mx=max(mx,x);
  }
  if(!cnt) return a[u];
  int x=sc-a[u],y=a[u]-x;
  if(sc-mx<x || x<0 || y<0) ans=0;
  //cout<<u<<" "<<y<<'\n';
  return y;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  for(int i=1,u,v;i<n;++i){
    cin>>u>>v; --u,--v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int r=dfs(0,-1);
  if(adj[0].size()!=1) ans=ans&&!r;
  cout<<(ans?"YES\n":"NO\n");
  return 0;
}

