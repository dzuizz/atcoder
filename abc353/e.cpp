#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node {
    int l, cnt, dep;
    bool is_leaf = 1;
    node* nx[26];

    node(int _l, int _dep): l(_l), dep(_dep), cnt(0) {
        fill(nx, nx + 26, nullptr);
    }

    int qry() {
        int ret = cnt * (cnt - 1) / 2;

        for (int i = 0; i < 26; ++i) if (nx[i] != nullptr)
            ret += nx[i]->qry();

        return ret;
    }

    node* get_nx(int _l) {
        if (nx[_l] == nullptr)
            nx[_l] = new node(_l, dep + 1), is_leaf = 0;
        
        return nx[_l];
    }
} *root;

signed main() {
    int n; cin >> n;

    root = new node(-1, 0);

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        node* cur = root;

        for (int j = 0; j < s.size(); ++j) {
            cur = cur->get_nx(s[j] - 'a');
            ++cur->cnt;
        }
    }

    cout << root->qry() << '\n';
}
