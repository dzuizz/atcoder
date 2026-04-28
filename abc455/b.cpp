#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int h,w; cin>>h>>w;
  string g[h];
  for(int i=0;i<h;++i) cin>>g[i];
  int ans=0;
  for(int ii=0;ii<h;++ii) for(int ji=0;ji<w;++ji)
  for(int ij=ii;ij<h;++ij) for(int jj=ji;jj<w;++jj){
    bool f=1;
    for(int a=ii;a<=ij;++a) for(int b=ji;b<=jj;++b)
      f&=(g[a][b]==g[ii+ij-a][ji+jj-b]);
    ans+=f;
  }
  cout<<ans<<'\n';
  return 0;
}
