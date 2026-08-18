#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+5,LOG=19;
vector<vector<int>> g_b(N),g_r(N),
  pa_b(LOG,vector<int>(N)),pa_r(LOG,vector<int>(N));
vector<int> dep_b(N),dep_r(N),caught(N);
int n,x,y;

int lca(vector<vector<int>>&g,vector<int>&dep,vector<vector<int>>&pa,int a,int b){
  if(dep[a]>dep[b]) swap(a,b);
  for(int i=LOG-1;i>=0;--i){
    if(dep[pa[i][b]]>=dep[a])
      b=pa[i][b];
  }

  if(a==b) return a;
  for(int i=LOG-1;i>=0;--i){
    if(pa[a][i]!=pa[b][i])
      a=pa[i][a],
      b=pa[i][b];
  }
  return pa[0][a];
}

void build_pa(vector<vector<int>>&pa){
  for(int j=0;j<LOG-1;++j){
    for(int i=1;i<=n;++i){
      pa[j+1][i]= pa[j][pa[j][i]];
    }
  }
}

void dfs_init(vector<vector<int>>&g,vector<int>&pa0,vector<int>&dep, int u){
  for(auto&v:g[u]){
    if(v!=pa0[u]){
      //cout<<u<<"-"<<v<<": "<<dep[u]<<'\n';
      pa0[v]=u;
      dep[v]=dep[u]+1;
      dfs_init(g,pa0,dep,v);
    }
  }
}

int dfs_caught(int u){
  caught[u]= 2*dep_b[u];
  int res=caught[u];
  for(auto&v: g_r[u]){
    if(v!= pa_r[0][u])
      if(dep_r[v] < dep_b[v])
        res=max(res, dfs_caught(v));
  }
  //cout<<u<<": "<<res<<'\n';
  return res;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n>>x>>y;
  vector<pair<int,int>> edges_r;
  for(int i=0;i<n-1;++i){ //red
    int a,b; cin>>a>>b;
    g_r[a].emplace_back(b);
    g_r[b].emplace_back(a);
    edges_r.emplace_back(a,b);
  }
  for(int i=0;i<n-1;++i){ //blue
    int a,b; cin>>a>>b;
    g_b[a].emplace_back(b);
    g_b[b].emplace_back(a);
  }
  
  dfs_init(g_b,pa_b[0],dep_b,y);
  //cout<<"dep_b: "; for(int i=1;i<=n;++i) cout<<dep_b[i]<<" "; cout<<'\n';
  build_pa(pa_b);

  //cout<<"---\n";
  dfs_init(g_r,pa_r[0],dep_r,x);
  build_pa(pa_r);

  int ans=dfs_caught(x);
  for(auto&[u,v]: edges_r){
    int d_b=dep_b[u]+dep_b[v]-2*dep_b[lca(g_b,dep_b,pa_b,u,v)];
    if(d_b>2){
      if(caught[u] || caught[v]) ans=-1;
    }
  }

  //cout<<"dep_b: "; for(int i=1;i<=n;++i) cout<<dep_b[i]<<" "; cout<<'\n';
  //cout<<"caught: "; for(int i=1;i<=n;++i) cout<<caught[i]<<" "; cout<<'\n';
  cout<<ans<<'\n';
  return 0;
}
