#include<iostream>
#include<queue>
#include<map>
using namespace std;

#define int long long

signed main() {
    int n; cin >> n;
    int a[n];

    map<int, priority_queue<int, vector<int>, greater<int> > > mp;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]].push(i);
    }

    int ans=0;
    for (auto p : mp) {
        auto pq = p.second;

        int lf=-1, prev=-1, cnt=-1, run=0, res=0;

        while (!pq.empty()) {
            int rg = pq.top(); pq.pop();
            cnt++;
            
            if (prev == -1) {
                prev = rg;
                lf = rg;
                continue;
            }

            run += (rg-prev-1)*cnt;
            res += run;
            prev = rg;
        }

        ans += res;
    }

    cout << ans << '\n';
}