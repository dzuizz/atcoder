#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  stack<char> st;
  string s; cin>>s;
  for(auto&c:s) st.emplace(c);
  int ans=0;
  while(st.size()){
    if(st.top()=='0'){
      st.pop();
      if(st.size()&&st.top()=='0') st.pop();
    } else st.pop();
    ++ans;
  }
  cout<<ans<<'\n';
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

