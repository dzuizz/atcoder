#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,Q; cin>>N>>Q;
  int nst[N],cnt[N],ans=0;
  for(int i=0;i<N;++i)nst[i]=i,cnt[i]=1;
  while(Q--){
    int T; cin>>T;
    if(T==1){
      int P,H; cin>>P>>H;
      if(--cnt[nst[--P]]==1) --ans;
      if(++cnt[nst[P]=--H]==2) ++ans;
    }else cout<<ans<<'\n';
  }
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

