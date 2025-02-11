#include<bits/stdc++.h>
using namespace std;
#define int long long
bool sieve[2000001];
vector<int>v;
void solve(){
  int N; cin>>N;
  int ans=0,s=sqrt(N);
	for(int i=2;i<=s;++i){
		if(sieve[i]) continue;
		v.push_back(i);
		for(int j=i*i;j<2000001;j+=i) sieve[j]=1;
	}
	for(int k=2;k<=(int)sqrt(s);++k){
		if(sieve[k]) continue;
		if(k*k*k*k*k*k*k*k>N) break;
		++ans;
	}
	for(int i=0;i<(int)v.size();++i) for(int j=i+1;j<(int)v.size()&&v[i]*v[j]<=s;++j){
		int x=v[i]*v[j];
		++ans;
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

