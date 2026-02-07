// ABC 260

#include <iostream>

int main() {
  std::string s; std::cin >> s;
  if (s[0] != s[1] && s[0] != s[2]) std::cout << s[0] << '\n';
  else if (s[1] != s[0] && s[1] != s[2]) std::cout << s[1] << '\n';
  else if (s[2] != s[0] && s[2] != s[1]) std::cout << s[2] << '\n';
  else std::cout << "-1\n";
}

