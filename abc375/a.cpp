// ABC 375

#include <iostream>

int main() {
  int n, cnt=0; std::cin >> n;
  std::string s; std::cin >> s;
  for (int i=0; i<n-2; ++i) {
    if (s[i] == '#' && s[i+1] == '.' && s[i+2] == '#') ++cnt;
  }
  std::cout << cnt << '\n';
}

