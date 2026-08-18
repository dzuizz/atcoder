#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  pair<int,int> events[n+1];
  for(int i=1;i<=n;++i){
    int t,x; cin>>t>>x;
    events[i]={t,x};
  }

  vector<int> pots[n+1];
  vector<bool> take(n+1,false);
  for(int i=1;i<=n;++i){
    auto&[t,x] = events[i];
    if(t==1){
      pots[x].emplace_back(i);
    }else if(pots[x].size()){
      int j = pots[x].back(); pots[x].pop_back();
      take[j] = true;
    }else{
      cout<<"-1\n";
      return 0;
    }
  }
  int res=0;
  vector<int> ans;
  for(int i=1,run=0;i<=n;++i){
    auto&[t,x] = events[i];
    if(t==1) ans.emplace_back(take[i]);
    else --run;
    run += take[i];
    res = max(res,run);
  }
  cout<<res<<'\n';
  for(auto&x:ans) cout<<x<<" ";
  cout<<'\n';
  return 0;
}
