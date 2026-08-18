#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> repunits;
  for(int i=0,p=0;i<12;++i){
    p=(p<<1)+(p<<3)+1;
    repunits.emplace_back(p);
  }
  vector<int> rep3;
  for(int&a:repunits) for(int&b:repunits) for(int&c:repunits)
    if(a<=b&&b<=c) rep3.emplace_back(a+b+c);
  sort(rep3.begin(),rep3.end());

  int n; cin>>n;
  cout<<rep3[n-1]<<'\n';
  return 0;
}
