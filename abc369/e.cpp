// ABC 369

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define int long long

signed main() {
  int N, M; cin >> N >> M;
  int adj[N][N];
  memset(adj, 0x3f, sizeof adj);
  for (int i=0; i<M; ++i) {
    int u, v, t; cin >> u >> v >> t;
    --u, --v;
    adj[u][v] = min(adj[u][v], t);
    adj[v][u] = min(adj[v][u], t);
  }
  int dis[N];
  memset(dis, 0x3f, sizeof dis);
  dis[0] = 0;
  priority_queue< pair<int,int> > pq;
  pq.push(make_pair(0, 0));
  while (pq.size()) {
    pair<int,int> cur = pq.top(); pq.pop();
    if (cur.first>dis[cur.second]) continue;
    for (int i=0; i<N; ++i) {
      if (adj[cur.second][i]==0x3f3f3f3f||dis[i]>cur.first+adj[cur.second][i]) continue;
      dis[i] = cur.first + adj[cur.second][i];
      pq.push(make_pair(dis[i], i));
    }
  }
  cout << dis[N-1] << '\n';
}

