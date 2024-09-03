// ABC 364

#include <iostream>
using namespace std;

int main() {
  int N; cin >> N;
  string prev = "";
  for (int i=0; i<N-1; ++i) {
    string s; cin >> s;
    if (s == "sweet" && prev == "sweet") {
      cout << "No\n";
      return 0;
    }
    prev = s;
  }
  cout << "Yes\n";
}

