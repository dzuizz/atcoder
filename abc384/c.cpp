#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int A[5]; for(auto&x:A) cin>>x;
  vector<pair<int,string>> v;
  for(int msk=0;msk<(1<<5);++msk){
    string s="";
    int x=0;
    for(int i=0;i<5;++i){
      if(msk>>i&1)continue;
      s+=('A'+i),x+=A[i];
    }
    v.emplace_back(x,s);
  }
  sort(v.begin(),v.end(),[&](const pair<int,string>&a,const pair<int,string>&b){
    return a.first==b.first?a.second<b.second:a.first>b.first;
  });
  for(int i=0;i<(int)v.size();++i)
    cout<<v[i].second<<'\n';
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

