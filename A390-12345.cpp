#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  string s="";
  for(int i=0;i<5;++i){
    string c; cin>>c;
    s+=c;
  }
  cout<<(s=="21345"||s=="13245"||s=="12435"||s=="12354"?"Yes\n":"No\n");
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

