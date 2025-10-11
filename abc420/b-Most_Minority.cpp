#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int n,m; cin>>n>>m;
  string s[n]; for(auto&x:s) cin>>x;
  int c[m]; memset(c,0,sizeof c);
  for(int i=0;i<n;++i) for(int j=0;j<m;++j)
    c[j]+=(s[i][j]=='1'?1:-1);
  int t[n]; memset(t,0,sizeof t);
  for(int i=0;i<n;++i) for(int j=0;j<m;++j)
    t[i]+=(abs(c[j])==n||((c[j]<0)==(s[i][j]=='1')));
  int k=*max_element(t,t+n);
  for(int i=0;i<n;++i) if(t[i]==k) cout<<i+1<<" ";
  cout<<'\n';
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

