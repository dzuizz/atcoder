#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int A,B,C; cin>>A>>B>>C;
  cout<<(A==B&&B==C||max({A,B,C})*2==A+B+C?"Yes\n":"No\n");
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t=1;
  // cin>>t;
  for(int i=1;i<=t;++i){
    //cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}

