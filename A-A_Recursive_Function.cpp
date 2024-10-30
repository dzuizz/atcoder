// ABC 273

#include <iostream>

int main() {
  int n, ans=1; std::cin >> n;
  for (size_t i=1; i<=n; ++i) ans *= i;
  std::cout << ans << '\n';
}

