#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > pos;

#define int long long

const pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, ans;
char a[505][505];

signed main() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    pair<int, int> s = {1, 1}, e = {n, n}; char c = 'R';
    priority_queue<pos, vector<pos>, greater<pos> > pq;
    vector<vector<int> > dis;

    pq.emplace(a[s.first][s.second] != c, s);

    dis = vector<vector<int>>(n + 2, vector<int>(n + 2, INT64_MAX));
    dis[s.first][s.second] = (a[s.first][s.second] != c);

    while (pq.size()) {
        pos cur = pq.top(); pq.pop();

        if (cur.second.first == e.first && cur.second.second == e.second) {
            ans += cur.first;
            break;
        }

        for (auto &p : dir) {
            pos nx = make_pair(cur.first, make_pair(cur.second.first + p.first, cur.second.second + p.second));
            if (nx.second.first < 0 || nx.second.first > n || nx.second.second < 0 || nx.second.second > n) continue;

            nx.first += a[nx.second.first][nx.second.second] != c;

            if (nx.first < dis[nx.second.first][nx.second.second]) {
                pq.push(nx);
                dis[nx.second.first][nx.second.second] = nx.first;
            }
        }
    }

    s = {1, n}, e = {n, 1}; c = 'B';

    pq = priority_queue<pos, vector<pos>, greater<pos> >();
    pq.emplace(a[s.first][s.second] != c, s);

    dis = vector<vector<int>>(n + 2, vector<int>(n + 2, INT64_MAX));
    dis[s.first][s.second] = (a[s.first][s.second] != c);

    while (pq.size()) {
        pos cur = pq.top(); pq.pop();

        if (cur.second.first == e.first && cur.second.second == e.second) {
            ans += cur.first;
            break;
        }

        for (auto &p : dir) {
            pos nx = make_pair(cur.first, make_pair(cur.second.first + p.first, cur.second.second + p.second));
            if (nx.second.first < 0 || nx.second.first > n || nx.second.second < 0 || nx.second.second > n) continue;

            nx.first += a[nx.second.first][nx.second.second] != c;

            if (nx.first < dis[nx.second.first][nx.second.second]) {
                pq.push(nx);
                dis[nx.second.first][nx.second.second] = nx.first;
            }
        }
    }

    cout << ans << '\n';
}