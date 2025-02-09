#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[102][102];
void solve(){
  int H,W,X,Y,C=0; cin>>H>>W>>X>>Y;
  for(int i=0;i<H+2;++i) for(int j=0;j<W+2;++j){
    if(!i||!j||i==H+1||j==W+1) a[i][j]='#';
    else cin>>a[i][j];
  }
  auto valid=[&](int i,int j){
    return a[i][j]!='#';
  };
  string T; cin>>T;
  for(auto&c:T){
    if(c=='U'&&valid(X-1,Y)) --X;
    else if(c=='R'&&valid(X,Y+1)) ++Y;
    else if(c=='L'&&valid(X,Y-1)) --Y;
    else if(c=='D'&&valid(X+1,Y)) ++X;
    if(a[X][Y]=='@') ++C,a[X][Y]='.';
  }
  cout<<X<<" "<<Y<<" "<<C<<'\n';
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

