#include<bits/stdc++.h>
using namespace std;
#define int long long
bool v[26];
void solve(){
  string s; cin>>s;
  for(auto&c:s) v[c-'a']=true;
  for(int i=0;i<26;++i) if(!v[i]){
    cout<<(char)('a'+i)<<'\n';
    return;
  }
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

