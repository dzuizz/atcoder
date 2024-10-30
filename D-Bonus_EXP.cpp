// ABC 369

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N; cin >> N;
  int A[N], dp[2][2];
  for (int i=0; i<N; ++i) cin >> A[i];
  dp[0][0] = A[0], dp[0][1] = 0;
  for (int i=1; i<N; ++i) {
    dp[i%2][0] = max(dp[(i+1)%2][1]+A[i], dp[(i+1)%2][0]);
    dp[i%2][1] = max(dp[(i+1)%2][0]+2*A[i], dp[(i+1)%2][1]);
  }
  cout << max(dp[(N+1)%2][0], dp[(N+1)%2][1]) << '\n';
}

