// ABC 369

#include <iostream>
using namespace std;

int main() {
  int A, B; cin >> A >> B;
  if (A == B) cout << "1\n";
  else if ((A-B)%2) cout << "2\n";
  else cout << "3\n";
}

