#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> dir[4]={{0,1},{1,0},{0,-1},{-1,0}};
int h,w,x,p,q,a[501][501], cur;
bool vis[502][502];
priority_queue<pair<int,pair<int,int>>>pq;
void solve(){
  cin>>h>>w>>x>>p>>q;
  for(int i=1;i<=h;++i)for(int j=1;j<=w;++j)
    cin>>a[i][j];
  for(int j=0;j<w+2;++j)vis[0][j]=1,vis[h+1][j]=1;
  for(int i=0;i<h+2;++i)vis[i][0]=1,vis[i][w+1]=1;
  cur=a[p][q],vis[p][q]=1;
  for(auto&v:dir){
    int nxi=v.first+p,nxj=v.second+q;
    if(vis[nxi][nxj])continue;
    pq.push({-a[nxi][nxj],{nxi,nxj}});
    vis[nxi][nxj]=1;
  }
  while(pq.size()){
    int s=-pq.top().first;
    int i=pq.top().second.first;
    int j=pq.top().second.second;
    pq.pop();
    if((long double)s>=(long double)cur/(long double)x)break;
    cur+=s;
    for(auto&v:dir){
      int nxi=v.first+i,nxj=v.second+j;
      if(vis[nxi][nxj])continue;
      pq.push({-a[nxi][nxj],{nxi,nxj}});
      vis[nxi][nxj]=1;
    }
  }
  cout<<cur<<'\n';
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

