#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  int l,r,m,v;
  node *lf,*rg;
  node(int _l,int _r):l(_l),r(_r),m((_l+_r)>>1),v(0){
    lf=nullptr,rg=nullptr;
  }
  void upd(int x){
    if(l==r){
      ++v;
      return;
    }
    if(x<=m){
      if(!lf)lf=new node(l,m);
      lf->upd(x);
    }else{
      if(!rg)rg=new node(m+1,r);
      rg->upd(x);
    }
    v=(lf?lf->v:0)+(rg?rg->v:0);
  }
  int qry(int x){
    if(r<x)return 0;
    if(l>=x)return v;
    return (lf?lf->qry(x):0)+(rg?rg->qry(x):0);
  }
} *root;
void solve(){
  int N; cin>>N;
  map<int,vector<int>>mp;
  int A[N],ans=0;
  for(int i=0;i<N;++i)cin>>A[i];
  for(int i=0;i<N;++i){
    int e; cin>>e;
    mp[A[i]].emplace_back(e);
  }
  sort(A,A+N);
  root=new node(0,(int)1e9);
  for(auto &p:mp){
    sort(p.second.begin(),p.second.end());
    for(auto &x:p.second)root->upd(x);
    for(auto &x:p.second)ans+=root->qry(x);
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

