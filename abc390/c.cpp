#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int H,W; cin>>H>>W;
  string a[H];
  for(int i=0;i<H;++i) cin>>a[i];
  int i1=H,i2=0,j1=W,j2=0;
  for(int i=0;i<H;++i) for(int j=0;j<W;++j) if(a[i][j]=='#')
    i1=min(i1,i),i2=max(i2,i),j1=min(j1,j),j2=max(j2,j);
  bool f=1;
  for(int i=i1;i<=i2;++i) for(int j=j1;j<=j2;++j) if(a[i][j]=='.')
    f=0;
  cout<<(f?"Yes\n":"No\n");
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t=1;
  // cin>>t;
  for(int i=1;i<=t;++i){
    //cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}

