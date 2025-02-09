#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int K; cin>>K;
  string S,T; cin>>S>>T;
  int n=(int)S.size(),m=(int)T.size();
  if(n-m==0){
    int cnt=0;
    for(int i=0;i<n;++i)
      cnt+=(S[i]!=T[i]);
    cout<<(cnt<=1?"Yes\n":"No\n");
  }else if(abs(n-m)==1){
    if(n<m) swap(S,T),swap(n,m);
    int l=0,r=0;
    while(l<m&&S[l]==T[l]) ++l;
    while(r<m&&S[n-r-1]==T[m-r-1]) ++r;
    cout<<((l+r)%m?"No\n":"Yes\n");
  }else cout<<"No\n";
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

