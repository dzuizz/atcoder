#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;++i){
    cin>>a[i];
  }
  int c[2]{};
  for(int i=0;i<n;++i) ++c[a[i]&1];
  cout<<(c[1]&1?"NO\n":"YES\n");
  return 0;
}

