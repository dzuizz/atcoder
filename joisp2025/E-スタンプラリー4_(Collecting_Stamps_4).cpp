#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=3e18;
struct node{
  int l,r,m;
  pair<int,pair<int,int>> v;  // (#01, #0, #1)
  node *lf,*rg;
  node(int _l,int _r): l(_l),r(_r),m((_l+_r)>>1) {
    v={0,{0,0}};
    if(l==r) return;
    lf=new node(l,m),rg=new node(m+1,r);
  }
  void upd(int x,int k){
    if(l==r){
      if(k) v.second={0,1};
      else v.second={1,0};
      return;
    }

    if(x<=m) lf->upd(x,k);
    else rg->upd(x,k);
    v={
      lf->v.first+rg->v.first+lf->v.second.first*rg->v.second.second,
      {
        lf->v.second.first+rg->v.second.first,
        lf->v.second.second+rg->v.second.second
      }
    };
  }
  pair<int,pair<int,int>> qry(int x,int y){
    if(x<=l&&r<=y) return v;
    if(x>r||l>y) return {0,{0,0}};
    pair<int,pair<int,int>> l=lf->qry(x,y);
    pair<int,pair<int,int>> r=rg->qry(x,y);
    return {
      l.first+r.first+l.second.first*r.second.second,
      {
        l.second.first+r.second.first,
        l.second.second+r.second.second
      }
    };
  }
} *root;
vector<int> solve(int N,int X,vector<int> A,vector<int> C,int Q,vector<int> K){
  for(auto&x:A) --x;
  vector<int> ret(Q);

  vector<pair<int,int>> v;  // (res[i], C[i])

  bool vis[N]; memset(vis,0,sizeof vis);
  int p[N][2],c[N],res=0,cnt=0;
  root=new node(0,4*N);
  for(int i=0;i<2*N;++i){
    if(vis[A[i]]){
      p[A[i]][1]=i;
      root->upd(i,1);
    }else if(vis[A[i]]=1){
      p[A[i]][0]=i;
      root->upd(i,0);
    }
  } v.emplace_back(root->qry(0,2*N-1).first,C[0]);

  for(int i=1;i<2*N;++i){
    root->upd(p[A[i-1]][1],0);
    root->upd(i+2*N-1,1);
    p[A[i-1]][0]=p[A[i-1]][1];
    p[A[i-1]][1]=i+2*N-1;
    v.emplace_back(root->qry(i,i+2*N-1).first,C[i]);
  }

  sort(v.begin(),v.end());
  int suff[2*N+1]; suff[2*N]=INF;
  for(int i=2*N-1;i>=0;--i) suff[i]=min(suff[i+1],v[i].second);

  vector<pair<int,int>> qry(Q);
  for(int i=0;i<Q;++i) qry[i]={K[i],i};
  sort(qry.begin(),qry.end());

  priority_queue<int> pq;
  pq.emplace(-INF);
  for(int i=0,j=0;i<Q;++i){
    while(j<2*N&&v[j].first<=qry[i].first){
      pq.emplace(X*v[j].first-v[j].second);
      ++j;
    }
    ret[qry[i].second]=min(X*qry[i].first-pq.top(),suff[j]);
  }

  return ret;
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int N,X; cin>>N>>X;
  vector<int> A(2*N),C(2*N);
  for(int i=0;i<2*N;++i) cin>>A[i];
  for(int i=0;i<2*N;++i) cin>>C[i];
  int Q; cin>>Q;
  vector<int> K(Q);
  for(int i=0;i<Q;++i) cin>>K[i];
  vector<int> ans=solve(N,X,A,C,Q,K);
  for(auto&x:ans){
    cout<<x<<'\n';
  }
  return 0;
}

/*
3 2
1 2 2 3 1 3
6 1 4 5 4 7
2
8
9

8 1
1 2 6 1 6 3 8 4 5 5 3 4 7 2 7 8
4 5 3 6 2 9 1 4 6 3 8 5 2 9 4 7
1
64

9 4
4 3 5 3 8 1 5 8 1 7 6 2 4 9 6 9 2 7
12 9 4 8 7 1 20 5 8 7 4 13 5 9 10 3 7 8
6
39
81
73
79
64
52
*/


