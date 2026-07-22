#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  bool a[(int)s.size()];
  int _a=0;

  for(auto&c:s){
    a[_a++]=c=='T';
    while(_a>1 && !a[_a-2] && a[_a-1]) _a-= 2;
  }
  cout<<_a<<'\n';
  return 0;
}
