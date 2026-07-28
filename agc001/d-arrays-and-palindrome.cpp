#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m; cin>>n>>m;
  int a[m];
  for(int i=0;i<m;++i) cin>>a[i];

  if(m==1){
    cout<<a[0]<<'\n';
    if(a[0]==1) cout<<"1\n1";
    else cout<<"2\n1 "<<a[0]-1<<'\n';
    return 0;
  }

  vector<int> o;
  for(int i=0;i<m;++i){
    if(a[i]&1) o.emplace_back(i);
  }
  if(o.size()>2) cout<<"Impossible\n";
  else{
    if(o.size()) swap(a[o[0]],a[0]);
    if(o.size()>1) swap(a[o[1]],a[m-1]);
    for(int i=0;i<m;++i) cout<<a[i]<<" ";
    cout<<'\n';
    a[0]-= 1,a[m-1]+= 1;
    cout<<m-(a[0]==0)<<'\n';
    for(int i=0;i<m;++i) if(a[i]) cout<<a[i]<<" ";
    cout<<'\n';
  }
  return 0;
}
