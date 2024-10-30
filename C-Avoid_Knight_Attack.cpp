#include <iostream>
#include <map>

int main() {
  int n, m; std::cin >> n >> m;
  std::map<std::pair<int,int>,bool> mp;
  std::pair<int,int> dir[9]={std::make_pair(0,0),std::make_pair(1,2),std::make_pair(2,1),std::make_pair(-1,2),std::make_pair(2,-1),std::make_pair(-2,1),std::make_pair(1,-2),std::make_pair(-1,-2),std::make_pair(-2,-1)};
  for (int i=0; i<m; ++i) {
    int a, b; std::cin >> a >> b;
    for (int i=0; i<9; ++i) {
      std::pair<int,int> nx = std::make_pair(a+dir[i].first,b+dir[i].second);
      if (0 < nx.first && nx.first <= n && 0 < nx.second && nx.second <= n)
        mp[nx]=1;
    }
  }
  std::cout << (long long)n*n - (long long)mp.size() << '\n';
}
