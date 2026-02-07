#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N; cin>>N;
  int K[N];
  map<int,int> mp[N];
  for(int i=0;i<N;++i){
    cin>>K[i];
    for(int j=0;j<K[i];++j){
      int x; cin>>x;
      ++mp[i][x];
    }
  }
  long double ans=0;
  for(int i=0;i<N;++i){
    for(int j=i+1;j<N;++j){
      int sum=0;
      for(auto&[p,q]:mp[j])
        sum+=q*mp[i][p];
      ans=max(ans,(long double)sum/(K[i]*K[j]));
    }
  }
  cout<<fixed<<setprecision(15)<<ans<<'\n';
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

