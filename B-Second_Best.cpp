// ABC 365

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N; cin >> N;
  pair<int,int> A[N];
  for (int i=0; i<N; ++i) {
    cin >> A[i].first;
    A[i].second = i+1;
  }
  sort(A, A+N);
  cout << A[N-2].second << '\n';
}

