#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[7*n];

    for (int i=0; i<7*n; i++) cin >> a[i];

    int sum=0;
    for (int i=0; i<7*n; i++) {
        if (i%7 == 0 && i) {
            cout << sum << " ";
            sum = 0;
        }

        sum += a[i];
    }

    cout << sum << '\n';
}