#include <iostream>

bool r[8], c[8];

int main() {
  for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
    char ch; std::cin >> ch;
    if (ch == '#') r[i]=1,c[j]=1;
  }
  int cnt=0;
  for (int i=0; i<8; ++i) for (int j=0; j<8; ++j)
    cnt += !r[i] && !c[j];
  std::cout << cnt << '\n';
}
