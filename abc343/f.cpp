#include<bits/stdc++.h>
using namespace std;
#define int long long
#define occ pair<int,int>
struct node{
  int l,r,m;
  node *lf,*rg;
  pair<occ,occ> v;
  node(int _l,int _r,int *a):l(_l),r(_r),m((_l+_r)>>1) {
    if(l==r){
      v={{a[l],1},{0,0}};
    }else{
      lf=new node(l,m,a),
      rg=new node(m+1,r,a);
      v=mrg(lf->v,rg->v);
    }
  }
  pair<occ,occ> mrg(pair<occ,occ> a,pair<occ,occ> b){
    occ mx{},nx{};
    for(auto p:{a.first,a.second,b.first,b.second}){
      if(mx.first==p.first) mx.second+=p.second;
      else if(nx.first<p.first){
        nx=p;
        if(mx.first<nx.first) swap(nx,mx);
      }else if(nx.first==p.first) nx.second+=p.second;
    }
    return {mx,nx};
  }
  void upd(int x,int val){
    if(l==r){
      v.first={val,1};
      return;
    }
    (x<=m?lf:rg)->upd(x,val);
    v=mrg(lf->v,rg->v);
  }
  pair<occ,occ> qry(int x,int y){
    if(x<=l && r<=y) return v;
    if(l>y || x>r) return {{0,0},{0,0}};
    return mrg(lf->qry(x,y),rg->qry(x,y));
  }
}*root;
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,q; cin>>n>>q;
  int a[n]; for(auto&x:a) cin>>x;
  root=new node(0,n-1,a);
  while(q--){
    int t,a,b; cin>>t>>a>>b;
    if(t==1){
      root->upd(--a,b);
    }else{
      cout<<root->qry(--a,--b).second.second<<'\n';
    }
  }
  return 0;
}

