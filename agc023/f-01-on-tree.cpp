#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<pair<int,int>,int> node;
namespace dsu{
  vector<int> pa,c0,c1;
  int n;
  void init(int _n){
    n=_n;
    pa.resize(n); iota(pa.begin(),pa.end(),0);
    c0=vector<int>(n,0);
    c1=vector<int>(n,0);
  }
  int f(int x){ return pa[x]==x?x:pa[x]=f(pa[x]); }
  bool yes(pair<int,int> p, int i){ return p.first==c1[i] && p.second==c0[i]; }
  int m(int a,int b){
    pa[b]=a;
    int inv=c1[a]*c0[b];
    c0[a]+=c0[b], c1[a]+=c1[b];
    return inv;
  }
  node get(int i){ return {{c1[i],c0[i]},i}; }
};
signed main(){
  auto cmp=[](const node&a, const node&b){
    return a.first.first * b.first.second > b.first.first * a.first.second;
  };

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  int pa[n]; for(int i=1;i<n;++i)
    cin>>pa[i],--pa[i];
  int v[n]; for(int i=0;i<n;++i)
    cin>>v[i];
  dsu::init(n);
  
  priority_queue<node,vector<node>,decltype(cmp)> pq; // {{#1,#0},i}
  for(int i=0;i<n;++i){
    dsu::c1[i]=v[i];
    dsu::c0[i]=v[i]^1;
    if(i) pq.push(dsu::get(i));
  }

  int ans=0;
  while(pq.size()){
    auto[c,i]=pq.top(); pq.pop();
    if(!dsu::yes(c,i)) continue;
    
    int p=dsu::f(pa[i]);
    ans += dsu::m(p,i);
    node nx = dsu::get(p);
    if(nx.second) pq.push(nx);
  }
  cout<<ans<<'\n';
  return 0;
}
