#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  map<int,int> mp;
  int ans=0;
  for(int i=0;i<n;++i){
    int x; cin>>x;
    ans+=x;
    ++mp[x];
  }
  vector<int> v;
  for(auto&p:mp) v.emplace_back(p.first*p.second);
  sort(v.begin(),v.end());
  for(int i=(int)v.size()-1;i>=max((int)v.size()-k,0ll);--i) ans-=v[i];
  cout<<ans<<'\n';
  return 0;
}
