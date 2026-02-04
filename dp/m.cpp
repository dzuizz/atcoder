#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int M=1e9+7;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i];
  }
  int dp[2][k+2]{};
  for(int j=1;j<=k+1;++j) dp[1][j]=1;
  for(int i=0;i<n;++i){
    for(int j=1;j<=k+1;++j){
      dp[i&1][j]=(dp[i&1^1][j]-dp[i&1^1][max(j-a[i]-1,0ll)]+M)%M;
      dp[i&1][j]+=dp[i&1][j-1],dp[i&1][j]%=M;
    }
  }
  cout<<(dp[n&1^1][k+1]-dp[n&1^1][k]+M)%M<<'\n';
  return 0;
}

