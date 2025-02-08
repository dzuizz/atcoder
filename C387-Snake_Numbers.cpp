#include<bits/stdc++.h>
using namespace std;
#define int long long
int binpow(int a,int b){
  if(!b) return 1;
  int tmp=binpow(a,b>>1);
  return tmp*tmp*(b&1?a:1);
}
int f(int x){
  if(x==9) return 0;
  vector<int>v;
  while(x){
    v.emplace_back(x%10);
    x/=10;
  }
  reverse(v.begin(),v.end());
  int n=(int)v.size(),ret=0;
  for(int i=1;i<v[0];++i)
    ret+=binpow(i,n-1);
  for(int i=2;i<n;++i) for(int j=1;j<10;++j)
    ret+=binpow(j,i-1);
  for(int i=1;i<=n;++i){
    if(i==n){
      ++ret;
      break;
    }
    ret+=min(v[0],v[i])*binpow(v[0],n-i-1);
    if(v[i]>=v[0]) break;
  }
  return ret;
}
void solve(){
  int L,R; cin>>L>>R;
  cout<<f(R)-f(L-1)<<'\n';
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

