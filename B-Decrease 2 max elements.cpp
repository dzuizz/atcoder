// ABC 368

#include <algorithm>
#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N; cin >> N;
  int A[N], ans=0;
  for (int i=0; i<N; ++i) cin >> A[i];
  while (1) {
    sort(A, A+N);
    if (A[N-2]<=0) break;
    --A[N-1], --A[N-2], ++ans;
  }
  cout << ans << '\n';
}

