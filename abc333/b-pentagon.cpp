#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  char a,b,c,d; cin>>a>>b>>c>>d;
  int x=max(a,b)-min(a,b),y=max(c,d)-min(c,d);
  x=max(x,5-x),y=max(y,5-y);
  cout<<(x==y?"Yes\n":"No\n");
  return 0;
}
