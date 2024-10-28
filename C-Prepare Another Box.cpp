#include <iostream>
#include <algorithm>

int main() {
  int n; std::cin >> n;
  int a[n]; for (size_t i=0; i<n; ++i) std::cin >> a[i];
  int b[n-1]; for (size_t i=0; i<n-1; ++i) std::cin >> b[i];
  std::sort(a,a+n), std::sort(b,b+n-1);
  int x=-1,ptr=n-2;
  for (int i=n-1; i>=0; --i) {
    if (ptr>=0 && a[i]<=b[ptr]) --ptr;
    else x = a[i];
  }
  if (ptr == -1) std::cout << x << '\n';
  else std::cout << "-1\n";
}

