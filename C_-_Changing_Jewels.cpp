#include <iostream>
using namespace std;
typedef long long ll;

ll n, x, y;

ll f(ll color, ll cnt, ll level) {
    if (level < 2) return color * cnt;
    if (color == 0) { // Red
        return f(0, cnt, level - 1) + f(1, x * cnt, level);
    } else {
        return f(0, cnt, level - 1) + f(1, y * cnt, level - 1);
    }
}

int main() {
    cin >> n >> x >> y;
    cout << f(0, 1, n) << '\n';
    return 0;
}