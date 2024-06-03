
#include <bits/stdc++.h>

int main() {
    int n, x, y; std::cin >> n >> x >> y;
    x += y;

    for (int i = 0, e; i < n; ++i) {
        std::cin >> e;
        if (e == x) std::cout << i + 1 << '\n';
    }
}