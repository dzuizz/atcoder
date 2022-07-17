#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define fi first
#define se second

int main() {
    int n, x, y, z; cin >> n >> x >> y >> z;
    ii a[n], b[n], ab[n], c[n];
    vector<int> ans;
    bool vis[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = -i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i].fi;
        b[i].se = -i;

        ab[i].fi = a[i].fi + b[i].fi;
        ab[i].se = -i;

        vis[i] = 0;
    }

    copy(a, a + n, c);
    sort(c, c + n, greater<ii>());
    for (int i = 0; i < x; i++) {
        ans.push_back(-c[i].se);
        vis[-c[i].se] = 1;
    }

    copy(b, b + n, c);
    sort(c, c + n, greater<ii>());
    int ind = 0, cnt = 0;
    while (cnt < y) {
        if (!vis[-c[ind].se]) {
            ans.push_back(-c[ind].se);
            vis[-c[ind].se] = 1;
            cnt++;
        }
        ind++;
    }

    copy(ab, ab + n, c);
    sort(c, c + n, greater<ii>());
    ind = cnt = 0;
    while (cnt < z) {
        if (!vis[-c[ind].se]) {
            ans.push_back(-c[ind].se);
            vis[-c[ind].se] = 1;
            cnt++;
        }
        ind++;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << '\n';
    }
}