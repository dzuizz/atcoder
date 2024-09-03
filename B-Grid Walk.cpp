// ABC 364

#include <iostream>
#include <unordered_map>
using namespace std;

int H, W;
pair<int,int> cur;
string A[50];

bool valid(pair<int,int> p) {
  return 0<=p.first && p.first<H && 0<=p.second && p.second<=W && A[p.first][p.second]=='.';
}

int main() {
  cin >> H >> W >> cur.first >> cur.second;
  --cur.first, --cur.second;
  for (int i=0; i<H; ++i) {
    cin >> A[i];
  }
  string s; cin >> s;
  for (auto &x : s) {
    pair<int,int> nx = make_pair(cur.first, cur.second);
    if (x=='U') --nx.first;
    else if (x=='R') ++nx.second;
    else if (x=='D') ++nx.first;
    else if (x=='L') --nx.second;
    if (valid(nx)) cur = nx;
  }
  cout << cur.first+1 << " " << cur.second+1 << '\n';
}

