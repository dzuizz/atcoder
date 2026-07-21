#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2005;
vector<int> g[N];
int cnt;

int dfs(int u,int p,int d){
  if(d==0) return 1;

  ++cnt;
  int ret=0;
  for(auto&v:g[u]){
    if(v!=p){
      ret+=dfs(v,u,d-1);
    }
  }
  return ret;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  for(int i=0;i<n-1;++i){
    int a,b; cin>>a>>b; --a,--b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int res=0;
  for(int c=0;c<n;++c){
    int mx=0;
    cnt=1;

    for(int&u:g[c]){
      int sz= dfs(u,c,k/2);
      mx=max(mx, sz);
    }
    if(k&1) res=max(res,cnt+mx);
    else res=max(res,cnt);
  }
  cout<<n-res<<'\n';
  return 0;
}
