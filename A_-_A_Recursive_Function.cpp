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

int f(int n) {
    if (n == 0) return 1;
    return n * f(n - 1);
}

int main() {
    int n; cin >> n;
    cout << f(n) << '\n';
}
