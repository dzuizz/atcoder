#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+5;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int n,m,k; cin>>n>>m>>k;
    string s; cin>>s;
    int dp[n][2][k+1],u[m],v[m]; //win?
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;++i) dp[i][0][0]=s[i]=='A',dp[i][1][0]=s[i]=='B';
    for(int i=0;i<m;++i) cin>>u[i]>>v[i],--u[i],--v[i];
    for(int i=1;i<=k;++i){
      for(int j=0;j<m;++j) if(!dp[u[j]][1][i]) dp[u[j]][1][i]=!dp[v[j]][0][i-1];
      for(int j=0;j<m;++j) if(!dp[u[j]][0][i]) dp[u[j]][0][i]=!dp[v[j]][1][i];
    }
    cout<<(dp[0][0][k]?"Alice\n":"Bob\n");
  }
  return 0;
}

