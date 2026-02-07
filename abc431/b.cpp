#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int x,n; cin>>x>>n;
  int a[n]; for(auto&x:a) cin>>x;
  int q; cin>>q;
  while(q--){
    int t; cin>>t; --t;
    x+=a[t],a[t]=-a[t];
    cout<<x<<'\n';
  }
  return 0;
}

