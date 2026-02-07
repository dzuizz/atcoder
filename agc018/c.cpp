#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int X,Y,Z; cin>>X>>Y>>Z;
  int n=X+Y+Z,C[n],summ=0;
  pair<int,int>a[n];
  for(int i=0;i<n;++i){
    cin>>a[i].first>>a[i].second>>C[i];
    a[i].first-=C[i],a[i].second-=C[i],summ+=C[i];
  }
  sort(a,a+n,[&](const pair<int,int>&a,const pair<int,int>&b){
    return a.first-a.second<b.first-b.second;
  });
  priority_queue<int,vector<int>,greater<int>>pq;
  int res[n],ans=0;
  for(int run=0,i=n-1;i>=0;--i){
    run+=a[i].first;
    pq.emplace(a[i].first);
    if(pq.size()>X){
      run-=pq.top();
      pq.pop();
    }
    res[i]=run;
  }
  while(pq.size()) pq.pop();
  for(int run=0,i=0;i<n-X;++i){
    run+=a[i].second;
    pq.emplace(a[i].second);
    if(pq.size()>Y){
      run-=pq.top();
      pq.pop();
    }
    if(pq.size()==Y)
      ans=max(ans,summ+run+res[i+1]);
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

