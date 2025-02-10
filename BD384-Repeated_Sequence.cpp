#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
  int N,S; cin>>N>>S;
  int A[N+1],pref[N+1];
  pref[0]=0;
  for(int i=1;i<=N;++i){
    cin>>A[i];
    pref[i]=pref[i-1]+A[i];
  }
  S%=pref[N];
  map<int,bool>mp;
  for(int i=0;i<=N;++i){
    if(mp.find(pref[i]-S)!=mp.end()){
      cout<<"Yes\n";
      return;
    }
    mp[pref[i]]=1;
  }
  map<int,int> cnt;
  ++cnt[0];
  int suff[N+1];
  for(int i=N,run=0;i>=0;--i)
    run+=A[i],++cnt[run],suff[i]=run;
  for(int i=1;i<=N;++i){
    --cnt[suff[i]];
    if(cnt[suff[i]]==0)cnt.erase(suff[i]);
    if(cnt.find(S-pref[i])!=cnt.end()){
      cout<<"Yes\n";
      return;
    }
  }
  cout<<(S?"No\n":"Yes\n");
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

