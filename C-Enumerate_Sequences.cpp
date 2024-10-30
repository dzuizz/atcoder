// ABC 367

#include <iostream>
using namespace std;

int R[8], A[8], N, K, summ;
bool flag;

void f(int i) {
  if (i == N) {
    summ=0, flag=1;
    for (int i=0; i<N; ++i) summ += A[i], flag=flag&&(!i||A[i]>A[i-1]);
    if (summ % K) return;
    for (int i=0; i<N; ++i) cout << A[i] << " ";
    cout << '\n';
  }
  for (int j=1; j<=R[i]; ++j) {
    A[i]=j;
    f(i+1);
  }
}

int main() {
  cin >> N >> K;
  for (int i=0; i<N; ++i) cin >> R[i];
  f(0);
}

