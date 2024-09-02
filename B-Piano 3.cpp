// ABC 369

#include <iostream>
using namespace std;

int main() {
  int N; cin >> N;
  int ans=0, A[2]={0,0};
  char Y;
  for (int i=0, X; i<N; ++i) {
    cin >> X >> Y;
    if (A[Y=='R']) ans += abs(X-A[Y=='R']);
    A[Y=='R'] = X;
  }
  cout << ans << '\n';
}

