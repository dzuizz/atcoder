#include <iostream>

int main() {
  std::string s; std::cin >> s;
  std::cout << (s == "ABC" || s == "ACB" || s == "BAC" || s == "BCA" || s == "CAB" || s == "CBA" ? "Yes\n" : "No\n");
}
