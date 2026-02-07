// ABC 363

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, T, P; cin >> N >> T >> P;
  int L[N];
  for (int i=0; i<N; ++i) cin >> L[i];
  sort(L, L+N);
  cout << max(T-L[N-P],0) << '\n';
}

