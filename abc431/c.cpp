#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m,k; cin>>n>>m>>k;
  int h[n]; for(auto&x:h) cin>>x;
  int b[m]; for(auto&x:b) cin>>x;
  sort(h,h+n,greater<int>());
  sort(b,b+m,greater<int>());
  int j=0;
  for(int i=0;i<k;++i){
    while(j<n && h[j]>b[i]) ++j;
    ++j;
  }
  cout<<(j>n?"No\n":"Yes\n");
  return 0;
}

