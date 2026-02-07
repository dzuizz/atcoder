// ABC 364

#include <algorithm>
#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N, X, Y; cin >> N >> X >> Y;
  int A[N], B[N], a=0, b=0;
  for (int i=0; i<N; ++i) cin >> A[i];
  for (int i=0; i<N; ++i) cin >> B[i];
  sort(A, A+N);
  sort(B, B+N);
  for (int i=N-1, summ=0; i>=0; --i) {
    summ += A[i], ++a;
    if (summ > X) break;
  }
  for (int i=N-1, summ=0; i>=0; --i) {
    summ += B[i], ++b;
    if (summ > Y) break;
  }
  cout << min(a, b) << '\n';
}

