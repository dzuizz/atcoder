#include <iostream>

int a[200010];

int main() {
  int n, m, dr=1; std::cin >> n >> m;
  for (int i=0; i<n; ++i) {
    int l, r; std::cin >> l >> r;
    a[r]=std::max(a[r],l);
  }
  long long ans=0;
  for (int r=1, dr=1; r<=m; ++r) {
    if (a[r]) dr=std::max(dr, a[r]+1);
    ans += r-dr+1;
  }
  std::cout << ans << '\n';
}
