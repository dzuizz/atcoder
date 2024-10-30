#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define fi first
#define se second

int main() {
    int n; cin >> n;
    map<int, int> m;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int e; cin >> e;

        if (!m[e])
            v.push_back(e);
        m[e]++;
    }

    sort(all(v), greater<int>());

    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (ind < sz(v))
            cout << m[v[ind++]] << '\n';
        else
            cout << "0\n";
    }
}
