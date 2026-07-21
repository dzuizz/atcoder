#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,x; cin>>n>>x;
  cout<<3*(n-__gcd(n,x))<<'\n';
}
