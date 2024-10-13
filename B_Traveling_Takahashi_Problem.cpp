#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define int long long

signed main() {
  int n, x=0, y=0; cin >> n;
  double ans = 0;
  for (int i=0, a, b; i<n; ++i) {
    cin >> a >> b;
    ans += sqrt((a-x)*(a-x) + (b-y)*(b-y));
    x = a, y = b;
  }
  ans += sqrt(x*x + y*y);  
  cout << fixed << setprecision(6) << ans << '\n';
}
