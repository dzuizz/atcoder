#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1<<20];
int f(int l,int r,int k){
  if(l==r){
    a[l]=k;
    return 0;
  }
  int m=(l+r)>>1;
  return f(l,m,k>>1)+f(m+1,r,(k>>1)+(k&1))+(k&1);
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,k; cin>>n>>k;
  cout<<f(0,(1<<n)-1,k)<<'\n';
  for(int i=0;i<(1<<n);++i) cout<<a[i]<<" ";
  cout<<'\n';
  return 0;
}

