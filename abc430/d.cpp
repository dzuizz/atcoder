#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int ans=0,r[n+2]; memset(r,0x3f,sizeof r);
  set<pair<int,int>> s;
  s.insert({0,0});
  for(int i=1;i<=n;++i){
    int x; cin>>x;
    r[i]=INT64_MAX;
    auto it=s.lower_bound({x,0});
    if(it!=s.end()){
      auto[rv,ri]=*it;
      if(r[ri]!=r[n+1]) ans-=r[ri];
      r[ri]=min(r[ri],rv-x);
      ans+=r[ri];
      r[i]=rv-x;
    }
    --it; auto[lv,li]=*it;
    if(r[li]!=r[n+1]) ans-=r[li];
    r[li]=min(r[li],x-lv);
    ans+=r[li];
    r[i]=min(r[i],lv-x);
    s.insert({x,i});
    cout<<ans<<'\n';
  }
  return 0;
}

