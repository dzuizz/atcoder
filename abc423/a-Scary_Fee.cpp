#include<iostream>
using namespace std;
typedef long long ll;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll x,c; cin>>x>>c;
  cout<<(ll)x*1000/(1000+c)/1000*1000<<'\n';
  return 0;
}

