#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int H,W,D,ans=0; cin>>H>>W>>D;
  bool S[H][W];
  for(int i=0;i<H;++i) for(int j=0;j<W;++j) {
    char c; cin>>c;
    S[i][j]=c=='#';
  }
	for(int ai=0;ai<H;++ai) for(int aj=0;aj<W;++aj) for(int bi=0;bi<H;++bi) for(int bj=0;bj<W;++bj) {
		if(S[ai][aj]||S[bi][bj]) continue;
		int cur=0;
		for(int i=0;i<H;++i)for(int j=0;j<W;++j)
			cur+=(!S[i][j]&&min(abs(i-ai)+abs(j-aj),abs(i-bi)+abs(j-bj))<=D);
		ans=max(ans,cur);
	}
	cout<<ans<<'\n';
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

