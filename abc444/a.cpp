#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin>>s;
  cout<<(s[0]==s[1] && s[1]==s[2] ? "Yes\n":"No\n");
  return 0;
}

