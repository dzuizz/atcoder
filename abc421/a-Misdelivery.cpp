#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  string a[n]; for(auto&x:a) cin>>x;
  int x; string y;
  cin>>x>>y;
  cout<<(a[--x]==y?"Yes\n":"No\n");
  return 0;
}

