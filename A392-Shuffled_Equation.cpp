#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int a,b,c; cin>>a>>b>>c;
  int m=max({a,b,c});
  cout<<(a*b*c==m*m?"Yes\n":"No\n");
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

