// ABC 375

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
  int n; std::cin >> n;

  int x=0, y=0, a, b;
  double ans=0;
  for (size_t i=0; i<n; ++i) {
    std::cin >> a >> b;
    ans += sqrt((long long)(a-x)*(a-x) + (long long)(b-y)*(b-y));
    x=a, y=b;
  }
  ans += sqrt((long long)x*x + (long long)y*y);
  std::cout << std::fixed << std::setprecision(6) << ans << '\n';
}

