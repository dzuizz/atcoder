#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;++i)
    cin>>a[i];
  int k=0;
  while(1){
    int cnt[2]{};
    for(int i=0;i<n;++i) ++cnt[i&1];
    if(!cnt[0]) break;
    if(cnt
  }
  cout<<(k&1?"Second\n":"First\n");
  return 0;
}

