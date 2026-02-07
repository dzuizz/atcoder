#include <iostream>
#include <vector>
#include <queue>

const int INF = 2147483647;
bool vis[200000];

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<int> adj[n];

  for (size_t i=0; i<m; ++i) {
    int a, b; std::cin >> a >> b; --a, --b;
    adj[a].emplace_back(b);
  }

  int ans=INF; vis[0]=1;
  std::queue<std::pair<int,int> > q;
  q.push(std::make_pair(1,0));
  while (q.size()) {
    std::pair<int,int> cur = q.front(); q.pop();
    for (auto &nx : adj[cur.second]) {
      if (nx == 0) ans = std::min(ans, cur.first);
      else if (vis[nx]) continue;
      else {
        q.push(std::make_pair(cur.first+1,nx));
        vis[nx]=1;
      }
    }
  }
  std::cout << (ans==INF?-1:ans) << '\n';
}

