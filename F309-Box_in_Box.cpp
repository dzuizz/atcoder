#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
  int l,r,m,v;
  node *lf,*rg;
  node(int _l,int _r):l(_l),r(_r),m((_l+_r)>>1),v(INT64_MAX){
    lf=nullptr,rg=nullptr;
  }
  void upd(int x,int val){
    if(l==r){
      v=min(v,val);
      return;
    }
    if(!lf) lf=new node(l,m);
    if(!rg) rg=new node(m+1,r);
    if(x<=m) lf->upd(x,val);
    else rg->upd(x,val);
    v=min(lf->v,rg->v);
  }
  int qry(int x){
    if(l>=x) return INT64_MAX;
    if(r<x) return v;
    return min((lf?lf->qry(x):INT64_MAX),(rg?rg->qry(x):INT64_MAX));
  }
} *root;
void solve(){
  int N; cin>>N;
  pair<int,pair<int,int>> a[N];
  for(int i=0;i<N;++i) {
    int h,w,d; cin>>h>>w>>d;
    if(w>d) swap(w,d);
    if(h>w) swap(h,w);
    if(w>d) swap(w,d);
    a[i]={h,{w,d}};
  }
  sort(a,a+N,[&](const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b){
    if(a.first==b.first) return a.second.first>b.second.first;
    return a.first<b.first;
  });
  root = new node(1,(int)1e9);
  bool f=0;
  for(int i=0;i<N;++i){
    root->upd(a[i].second.first,a[i].second.second);
    f=f||root->qry(a[i].second.first)<a[i].second.second;
  }
  cout<<(f?"Yes\n":"No\n");
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

