#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x){
  int res=0;
  while(x){
    res+=x%10;
    x/=10;
  }
  return res;
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n+1]; a[0]=1;
  for(int i=1;i<=n;++i){
    a[i]=0;
    for(int j=0;j<i;++j) a[i]+=f(a[j]);
  }
  cout<<a[n]<<'\n';
  return 0;
}

