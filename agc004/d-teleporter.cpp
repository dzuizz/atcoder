#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int N=1e5+5;

int n,k,a[N], ans=0;
vector<int> nx[N];

int dfs(int u,int d){
  int res=d>k?d-k+1:-1;

  for(auto&v:nx[u]){
    res=max(res, dfs(v,d+1));
  }

  if(res==d){
    ++ans;
    return -1;
  }
  return res;
}

signed main(){
  cin>>n>>k;
  for(int i=0;i<n;++i) cin>>a[i],--a[i];

  for(int i=1;i<n;++i) // ignore 0
    nx[a[i]].emplace_back(i);

  ans+= a[0]!=0;
  dfs(0,0);

  cout<<ans<<'\n';
  return 0;
}
