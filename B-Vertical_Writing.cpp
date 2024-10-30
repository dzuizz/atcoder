// ABC 366

#include <iostream>
using namespace std;

int main() {
  int N, maxi=0; cin >> N;
  string A[N];
  for (int i=0; i<N; ++i) {
    cin >> A[i];
    maxi = max(maxi, (int)A[i].size());
  }
  string ans[maxi];
  for (int i=N-1; i>=0; --i) {
    for (int j=0; j<(int)A[i].size(); ++j) {
      while ((int)ans[j].size()<N-i-1) ans[j] += "*";
      ans[j] += A[i][j];
    }
  }
  for (int i=0; i<maxi; ++i) cout << ans[i] << '\n';
}

