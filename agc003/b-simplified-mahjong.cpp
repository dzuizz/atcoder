#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;++i) cin>>a[i];
  int ans=0,p=0;
  for(int i=0;i<n;++i){
    int x=min(p,a[i]);
    ans+=x,a[i]-=x;
    ans+=a[i]>>1,p=a[i]&1;
  }
  cout<<ans<<'\n';
  return 0;
}
