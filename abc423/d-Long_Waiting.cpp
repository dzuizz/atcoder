#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k,t=0; cin>>n>>k;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // (t,c)
  int tot=0;
  for(int i=0;i<n;++i){
    int a,b,c; cin>>a>>b>>c;
    t=max(t,a);
    while(pq.size()&&pq.top().first<=t) tot-=pq.top().second,pq.pop();
    while(tot+c>k){
      t=pq.top().first;
      while(pq.size()&&pq.top().first==t) tot-=pq.top().second,pq.pop();
    }
    cout<<t<<'\n';
    pq.emplace(t+b,c); tot+=c;
  }
  return 0;
}

