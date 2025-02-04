#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  string s; cin>>s;
  unordered_map<char,char>mp;
  mp['N']='S',mp['E']='W',mp['W']='E',mp['S']='N';
  for(auto&c:s)cout<<mp[c];
  cout<<'\n';
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
