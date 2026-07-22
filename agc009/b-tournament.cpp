#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=1e5+5;
vector<int> g[N];
int dfs(int u){
  multiset<int> sz;
  for(int&v:g[u]){
      sz.emplace(-dfs(v));
  }
  int ret=0;

  int off=1;
  //cout<<u<<"(sz): ";
  for(auto&x:sz){
    //cout<<x<<" ";
    ret=max(ret,off-x);
    ++off;
  }
  //cout<<'\n';
  //cout<<u<<": "<<ret<<'\n';
  return ret;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  for(int i=2;i<=n;++i){
    int x; cin>>x;
    g[x].emplace_back(i);
  }

  cout<<dfs(1)<<'\n';
  return 0;
}
