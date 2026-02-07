// ABC 368

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N, K; cin >> N >> K;
  int A[N];
  for (int i=0; i<N; ++i) cin >> A[i];
  for (int i=N-K; i<N; ++i) cout << A[i] << " ";
  for (int i=0; i<N-K; ++i) cout << A[i] << " ";
  cout << '\n';
}

