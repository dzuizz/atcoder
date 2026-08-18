#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin>>t;
  string xx="(xx)";
  while(t--){
    string a,b; cin>>a>>b;
    string res[2]; int _res=0;
    for(auto&s:{a,b}){
      vector<char> v;
      int n=0;
      for(auto&c:s){
        if(n>2 && c==')' && v[n-1]=='x' && v[n-2]=='x' && v[n-3]=='(')
          v.erase(v.begin()+n-3), --n;
        else v.emplace_back(c), ++n;
      }
      for(auto&x:v) res[_res]+=x;
      ++_res;
    }
    cout<<(res[0]==res[1]?"Yes\n":"No\n");
  }
  return 0;
}
