#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int a[4];
  for(int i=0;i<4;++i) cin>>a[i];
  sort(a,a+4);
  int A=a[0],B=a[1],C=a[2],D=a[3];
  cout<<(
    A==B&&B==C&&C!=D
  ||A==B&&B!=C&&C==D
  ||A!=B&&B==C&&C==D
  ?"Yes\n":"No\n");
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

