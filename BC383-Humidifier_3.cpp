#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>dir[4]={{0,1},{-1,0},{1,0},{0,-1}};
void solve(){
	int h,w,d,ans=0;
	cin>>h>>w>>d;
	bool s[h][w];
	memset(s,0,sizeof s);
	queue<pair<int,pair<int,int>>> q;
	for(int i=0;i<h;++i)for(int j=0;j<w;++j){
		char c;
		cin>>c;
		s[i][j]=c!='.';
		if(c=='H'){
			q.push(make_pair(0,make_pair(i,j)));
		}
	}
	while(q.size()){
		pair<int,pair<int,int>>cur=q.front(); q.pop();
		++ans;
		int c=cur.first;
		int i=cur.second.first;
		int j=cur.second.second;
		if(c==d)continue;
		for(pair<int,int>&p:dir){
			pair<int,int>nx=make_pair(i+p.first,j+p.second);
			if(nx.first>=0&&nx.first<h&&nx.second>=0&&nx.second<w&&s[nx.first][nx.second]==0){
				q.push(make_pair(c+1,nx));
				s[nx.first][nx.second]=1;
			}
		}
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

