#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,W; cin>>N>>W;
  vector<pair<int,int>> v[W];
  for(int i=0;i<N;++i){
    int x,y; cin>>x>>y;
    v[--x].emplace_back(y,i);
  }
  int d[N],l[N],sz=N; memset(d,0,sizeof d);
  for(int i=0;i<W;++i){
    sort(v[i].begin(),v[i].end());
    sz=min(sz,(int)v[i].size());
    for(int j=0;j<(int)v[i].size();++j){
      d[j]=max(d[j],v[i][j].first);
      l[v[i][j].second]=j;
    }
  }
  for(int i=sz;i<N;++i) d[i]=3e18;
  int Q; cin>>Q;
  while(Q--){
    int T,A; cin>>T>>A;
    cout<<(d[l[--A]]>T?"Yes\n":"No\n");
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

