// ABC 367

#include <iostream>
using namespace std;

#define int long long

signed main() {
  int A, B, C; cin >> A >> B >> C;
  if (B<C) cout << (B<A&&A<C?"No\n":"Yes\n");
  else cout << (C<A&&A<B?"Yes\n":"No\n");
}

