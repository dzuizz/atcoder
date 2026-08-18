#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  bool f[m]{};
  for(int i=0;i<n;++i){
    int l; cin>>l;
    int bx=0;
    for(int j=0;j<l;++j){
      int x; cin>>x; --x;
      if(!(bx||f[x])) bx=x+1,f[x]=1;
    }
    cout<<bx<<'\n';
  }
  return 0;
}

