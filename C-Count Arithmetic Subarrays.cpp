// ABC 369

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N; cin >> N;
  int A[N];
  for (size_t i=0; i<N; ++i) cin >> A[i];
  int ans=N, j=0;
  for (size_t i=1; i<N-1; ++i) {
    if (A[i+1]-A[i]!=A[i]-A[i-1]) {
      ans+=(i-j)*(i-j+1)/2;
      j=i;
    }
  }
  ans+=(N-j-1)*(N-j)/2;
  cout << ans << '\n';
}

