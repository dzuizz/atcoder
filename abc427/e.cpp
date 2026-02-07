#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> dir[4]={
  {0,1},
  {1,0},
  {0,-1},
  {-1,0}
};
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int h,w; cin>>h>>w;
  string g[h];
  for(auto&x:g) cin>>x;
  pair<int,int> t;
  for(int i=0;i<h;++i) for(int j=0;j<w;++j) if(g[i][j]=='T'){
    t={i,j};
  }
  pair<int,int> x{},y{};
  for(int i=0;i<h;++i) for(int j=0;j<w;++j) if(g[i][j]=='#'){
    if(i<t.first) x.first=max(x.first,i+1);
    else x.second=max(x.second,h-i);
    if(j<t.second) y.first=max(y.first,j+1);
    else x.second=max(y.second,w-j);
  }
  queue<pair<int,int>> q; q.emplace(t);
  int vi[h][w]; memset(vi,-1,sizeof vi);
  vi[t.first][t.second]=0;
  while(q.size()){
    auto[i,j]=q.front(); q.pop();
    int dx=abs(i-t.first),dy=abs(j-t.second);
    if(i<t.first&&dx>=x.second);
    }
    for(auto&[di,dj]:dir){
      int ni=i+di,nj=j+dj;
      if(ni<0||ni>=h||nj<0||nj>=w||vi[ni][nj]!=-1||g[ni][nj]=='#') continue;
      vi[ni][nj]=vi[i][j]+1;
      q.emplace(ni,nj);
    }
  }
  return 0;
}

