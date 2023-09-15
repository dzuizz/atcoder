#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

#define int long long
#define fi first
#define se second

typedef pair<int, int> ii;

signed main() {
    int grid[9];

    for (int i=0; i<9; i++) cin >> grid[i];

    vector<vector<int> > same = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    vector<int> order;
    for (int i=0; i<9; i++) order.push_back(i);
    int total=0, cnt=0;

    do {
        bool flag = 1;
        for (auto x : same) {
            int a = x[0], b = x[1], c = x[2];

            if (grid[a] == grid[b] && order[a] < order[c] && order[b] < order[c]) flag = 0;
            if (grid[a] == grid[c] && order[a] < order[b] && order[c] < order[b]) flag = 0;
            if (grid[b] == grid[c] && order[b] < order[a] && order[c] < order[a]) flag = 0;
        }

        if (flag) cnt++;
        
        total++;
    } while (next_permutation(order.begin(), order.end()));

    cout << fixed << setprecision(9) << (double)cnt/total << '\n';
}