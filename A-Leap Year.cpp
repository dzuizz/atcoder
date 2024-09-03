// ABC 365

#include <iostream>
using namespace std;

int main() {
  int Y; cin >> Y;
  if (Y%4) cout << "365\n";
  else if (Y%100) cout << "366\n";
  else if (Y%400) cout << "365\n";
  else cout << "366\n";
}

