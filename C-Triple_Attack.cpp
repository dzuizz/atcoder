// ABC 368

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N, T=0; cin >> N;
  while (N--) {
    int H; cin >> H;
    T += (H/5)*3;
    H %= 5;
    while (H>0) {
      if (++T%3) --H;
      else H -= 3;
    }
  }
  cout << T << '\n';
}

