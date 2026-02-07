#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int t[m]{},c[m]{};
  for(int i=0;i<n;++i){
    int a,b; cin>>a>>b;
    t[--a]+=b,++c[a];
  }
  cout<<fixed<<setprecision(8);
  for(int i=0;i<m;++i) cout<<(double)t[i]/c[i]<<'\n';
  return 0;
}

