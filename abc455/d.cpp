#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int up[2*n+1]{},down[2*n+1]{};
  for(int i=1;i<=n;++i){
    up[i+n]=i;
    down[i]=i+n;
  }
  while(q--){
    int a,b; cin>>a>>b;
    up[down[a]]=0;
    down[a]=b;
    up[b]=a;
  }
  for(int i=n+1;i<=2*n;++i){
    int cnt=0,k=i;
    while(k=up[k]) ++cnt;
    cout<<cnt<<" ";
  }
  cout<<'\n';
  return 0;
}
