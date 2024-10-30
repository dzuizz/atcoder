// ABC 001 

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int N; cin >> N;
  pair<int,int> A[N];

  char c;
  for (int i=0; i<N; ++i) {
    cin >> A[i].first >> c >> A[i].second;
  }
  sort(A, A+N);

  stack<pair<int,int> > st;
  for (int i=N-1; i>=0; ++i) {
    int lf=A[i].first, rg=A[i].second;
    while (st.top().
}

