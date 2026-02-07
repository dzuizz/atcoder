#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int n,h; cin>>n>>h;
    int t=0,l=h,r=h;
    bool flag=1;
    for(int i=0;i<n;++i){
      int a,b,c; cin>>a>>b>>c;
      l-=a-t,r+=a-t,t=a;
      l=max(l,b),r=min(r,c);
      if(l>r) flag=0;
    }
    cout<<(flag?"Yes\n":"No\n");
  }
  return 0;
}

