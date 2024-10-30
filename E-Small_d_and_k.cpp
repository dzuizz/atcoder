#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <cmath>

#include <unordered_map>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define fr front()
#define bk back()
#define pb push_back
#define pf push_front
#define ins insert
#define fi first
#define se second

#define FOR(i, a, b, inc) for (int i = a; i < b; i += inc)
#define RFOR(i, a, b, inc) for (int i = b - 1; i >= a; i -= inc)
#define REP(i, a) FOR(i, 0, a, 1)
#define RREP(i, a) RFOR(i, 0, a, 1)
#define each(a, x) for (auto& a: x)

const int INF = 1e9;
const int MOD = 1e9 + 7;

int gcd(int a, int b);
int pow(int a, int b);

// int solve() {}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vi edges[n + 5];

    REP(i, m) {
        int u, v; cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    int q; cin >> q;
    while (q--) {
        int x, k; cin >> x >> k;

        queue<ii> q;
        vi vis(n + 5, 0);
        q.push({x, 0});
        vis[x] = 1;

        int ans = 0;
        while (!q.empty()) {
            ii cur = q.front(); q.pop();

            ans += cur.fi;
            if (cur.se == k) continue;

            each (e, edges[cur.fi]) {
                if (!vis[e]) {
                    vis[e] = 1;
                    q.push({e, cur.se + 1});
                }
            }
        }

        cout << ans << '\n';
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int pow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int x = pow(a, b/2);
    if (b%2 == 0) return x*x;
    return x*x*a;
}