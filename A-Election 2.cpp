// ABC 368

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int N, T, A; cin >> N >> T >> A;
  cout << (T>=(N+1)/2||A>=(N+1)/2?"Yes\n":"No\n");
}

