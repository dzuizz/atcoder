// ABC 365

#include <algorithm>
#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N, M; cin >> N >> M;
  int A[N], lo=0, hi=0;
  for (int i=0; i<N; ++i) {
    cin >> A[i];
    hi += A[i];
  }
  if (hi <= M) cout << "infinite\n";
  else {
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2, cnt=0;
      for (int i=0; i<N; ++i) cnt += min(A[i], mid);
      if (cnt <= M) lo = mid;
      else hi = mid - 1;
    }
    cout << lo << '\n';
  }
}

