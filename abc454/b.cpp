#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int cnt=0;
  bool f[m]{},a=1;
  for(int i=0;i<n;++i){
    int x; cin>>x; --x;
    if(f[x]) a=0;
    else ++cnt;
    f[x]=1;
  }
  cout<<(a?"Yes\n":"No\n")<<(cnt==m?"Yes\n":"No\n");
  return 0;
}
