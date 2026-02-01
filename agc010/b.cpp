#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int a[n],summ=0; for(int i=0;i<n;++i){
    cin>>a[i];
    summ+=a[i];
  }
  bool ans=1;
  int d[n]; for(int i=0;i<n-1;++i){
    d[i]=a[i+1]-a[i];
  } d[n-1]=a[0]-a[n-1];
  if(summ%(n*(n+1)/2)) ans=0;
  else{
    int k=summ/(n*(n+1)/2);
    for(int i=0;i<n&&ans;++i){
      if(k<d[i] || (k-d[i])%n){
        ans=0;
      }
    }
  }
  cout<<(ans?"YES\n":"NO\n");
  return 0;
}

