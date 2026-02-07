#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=505,W=N*N,INF=3e18;
int w[N],h[N],b[N];
int dp[2][W],n,ans;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n;
  for(int i=0;i<n;++i) cin>>w[i]>>h[i]>>b[i];
  for(auto&x:dp[0]) x=-INF;
  dp[0][W/2+w[0]]=b[0],dp[0][W/2-w[0]]=h[0];
  for(int i=1;i<n;++i){
    for(int j=0;j<W;++j)  // reset
      dp[i&1][j]=-INF;
    for(int j=w[i];j<W;++j)  // body
      dp[i&1][j]=max(dp[i&1][j],dp[i&1^1][j-w[i]]+b[i]);
    for(int j=0;j<W-w[i];++j)  // head
      dp[i&1][j]=max(dp[i&1][j],dp[i&1^1][j+w[i]]+h[i]);
  }
  /*
  int k=5;
  for(int i=0;i<n;++i){
    for(int j=W/2-k;j<=W/2+k;++j) cout<<(dp[i][j]==dp[0][0]?-1:dp[i][j])<<" ";
    cout<<'\n';
  }*/
  for(int i=W/2;i<W;++i)
    ans=max(ans,dp[n&1^1][i]);
  cout<<ans<<'\n';
  return 0;
}


