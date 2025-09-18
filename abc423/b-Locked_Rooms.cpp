#include<iostream>
using namespace std;
typedef long long ll;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int l[n];
  for(int i=0;i<n;++i) cin>>l[i];
  int min1=0,max1=0;
  for(int i=0;i<n;++i) if(l[i]) max1=i;
  for(int i=n-1;i>=0;--i) if(l[i]) min1=i;
  cout<<max1-min1<<'\n';
  return 0;
}

