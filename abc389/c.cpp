#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int Q, ptr=0; cin>>Q;
  vector<pair<int,int>> v;
  v.emplace_back(0,0);
  while(Q--){
    int T; cin>>T;
    if(T==1){
      int l; cin>>l;
      v.emplace_back(v.rbegin()->first+v.rbegin()->second,l);
    }else if(T==2){
      ++ptr;
    }else{
      int k; cin>>k;
      cout<<v[ptr+k].first-v[ptr+1].first<<'\n';
    }
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

