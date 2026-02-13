#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,s,t; cin>>n>>s>>t;
  int a[n],summ=0; for(int i=0;i<n;++i)
    cin>>a[i],summ+=a[i];
  cout<<(summ<=60*(t-s) ? "Yes\n" : "No\n");
  return 0;
}

