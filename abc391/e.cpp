#include<bits/stdc++.h>
using namespace std;
#define int long long
string S;
map<pair<pair<int,int>,bool>,int> mp;
int f(int l,int r,bool k){
  if(mp.find(make_pair(make_pair(l,r),k))!=mp.end()) return mp[make_pair(make_pair(l,r),k)];
  if(l==r) return (S[l]=='1')!=k;
  int s=(r-l+1)/3,a[3][2]={
    {f(l,l+s-1,k),f(l,l+s-1,!k)},
    {f(l+s,r-s,k),f(l+s,r-s,!k)},
    {f(r-s+1,r,k),f(r-s+1,r,!k)},
  };
  return mp[make_pair(make_pair(l,r),k)]=min({
    a[0][0]+a[1][0]+a[2][0],
    a[0][1]+a[1][0]+a[2][0],
    a[0][0]+a[1][1]+a[2][0],
    a[0][0]+a[1][0]+a[2][1]
  });
}
void solve(){
  int N; cin>>N;
  cin>>S;
  int x=1; for(int i=0;i<N;++i) x*=3;
  cout<<max(f(0,x-1,0),f(0,x-1,1))<<'\n';
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

