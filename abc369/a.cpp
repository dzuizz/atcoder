// ABC 369

#include <iostream>

int main() {
  int A, B; std::cin >> A >> B;
  std::cout << (A == B ? 1 : A&1^(B&1) ? 2 : 3) << '\n';
}

