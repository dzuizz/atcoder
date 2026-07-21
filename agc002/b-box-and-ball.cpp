#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int x[m],y[m];
  for(int i=0;i<m;++i){
    cin>>x[i]>>y[i];
    --x[i],--y[i];
  }

  int sz[n]; for(auto&x:sz) x=1;
  bool red[n]; memset(red,0,sizeof red);
  red[0]=1;

  for(int i=0;i<m;++i){
    ++sz[y[i]],--sz[x[i]];
    red[y[i]]|= red[x[i]];
    red[x[i]]&= sz[x[i]]>0;
  }

  int res=0;
  for(int i=0;i<n;++i) res+=red[i];
  cout<<res<<'\n';
  return 0;
}
