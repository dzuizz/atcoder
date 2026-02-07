#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  string s; cin>>s;
  int cnt=0;
  for(auto&c:s) cnt+=c=='2';
  cout<<string(cnt,'2')<<'\n';
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

