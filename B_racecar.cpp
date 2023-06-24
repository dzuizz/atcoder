#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string a[n];

    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) continue;
            string ij = a[i] + a[j], ji = ij;
            reverse(ji.begin(), ji.end());

            if (ji == ij) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
}