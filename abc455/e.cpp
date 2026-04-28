#include<bits/stdc++.h>
using namespace std;
#define int long long
#define m(x) x>2?x-3:x
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  int cnt[3]{};

  map<int,int> m1[3];
  map<pair<int,int>,int> m2[3]; // exclude
  map<pair<pair<int,int>,int>,int> m3;
  for(int i:{0,1,2}) ++m1[i][0];
  for(int i:{0,1,2}) ++m2[i][{0,0}];
  ++m3[{{0,0},0}];

  int ans=0;
  for(int i=0;i<n;++i){
    ++cnt[s[i]-'A'];
    int d[3]={cnt[0]-cnt[1],cnt[1]-cnt[2],cnt[2]-cnt[0]};

    int sm1=0; for(int i:{0,1,2}) sm1+=m1[i][d[i]];
    int sm2=0; for(int i:{0,1,2}) sm2+=m2[i][{d[m(i+1)],d[m(i+2)]}];
    int sm3=m3[{{d[0],d[1]},d[2]}];
    ans+=i+1-(sm1-sm2+sm3);

    for(int i:{0,1,2}) ++m1[i][d[i]];
    for(int i:{0,1,2}) ++m2[i][{d[m(i+1)],d[m(i+2)]}];
    ++m3[{{d[0],d[1]},d[2]}];
  }
  cout<<ans<<'\n';
  return 0;
}
