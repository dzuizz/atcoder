#include<bits/stdc++.h>
using namespace std;
#define int long long
int g[2000][2000];
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int u[n],d[n],l[n],r[n];
  for(int i=0;i<n;++i){
    cin>>u[i]>>d[i]>>l[i]>>r[i]; --u[i],--d[i],--l[i],--r[i];
    for(int a=u[i];a<=d[i];++a) for(int b=l[i];b<=r[i];++b)
      ++g[a][b];
  }
  int ans=0,p[n]; memset(p,0,sizeof p);
  for(int a=0;a<2000;++a) for(int b=0;b<2000;++b)
    if(!g[a][b]) ++ans;
  for(int i=0;i<n;++i){
    for(int a=u[i];a<=d[i];++a) for(int b=l[i];b<=r[i];++b)
      if(g[a][b]==1) ++p[i];
  }
  for(int i=0;i<n;++i) cout<<ans+p[i]<<'\n';
  return 0;
}

