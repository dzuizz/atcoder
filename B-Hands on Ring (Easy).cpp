#include <iostream>

int main() {
  int n, q; std::cin >> n >> q;
  int l=1,r=2,ans=0;
  for (size_t i=0; i<q; ++i) {
    char h;
    int t;
    std::cin >> h >> t;

    if (h == 'L') {
      if ((t-l+n)%n > (r-l+n)%n) {
        ans += (l-t+n)%n, l=t;
      } else {
        ans += (t-l+n)%n, l=t;
      }
    } else {
      if ((t-r+n)%n > (l-r+n)%n) {
        ans += (r-t+n)%n, r=t;
      } else {
        ans += (t-r+n)%n, r=t;
      }
    }
  }
  std::cout << ans << '\n';
}

