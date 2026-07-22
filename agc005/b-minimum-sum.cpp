#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i]; --a[i];
  }
  int p[n]; for(int i=0;i<n;++i){
    p[a[i]]=i;
  }
  set<int> r,l;
  r.emplace(-1), r.emplace(n);
  l.emplace(1), l.emplace(-n);

  int ans=0;
  for(int i=0;i<n;++i){
    int rr = *r.lower_bound(p[i]);
    int ll = -*l.lower_bound(-p[i]);

    //cout<<i<<": "<<ll<<" "<<rr<<'\n';
    ans += (rr-p[i]) * (p[i]-ll) * (i+1);

    r.emplace(p[i]);
    l.emplace(-p[i]);
  }
  cout<<ans<<'\n';
  return 0;
}
