#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int a,b; cin>>a>>b;
  if(a>0) cout<<"Positive\n";
  else if(b>=0) cout<<"Zero\n";
  else cout<<((b-a)&1?"Positive\n":"Negative\n");
}
