#include <iostream>

int main() {
  int n, c; std::cin >> n >> c;
  int ans=0,pre=-1000;
  for (int i=0; i<n; ++i) {
    int e; std::cin >> e;
    if (e-pre>=c) ++ans,pre=e;
  }
  std::cout << ans << '\n';
}

