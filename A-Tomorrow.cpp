#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[2], b[3]; 

    for (int i:{0,1}) cin >> a[i];
    for (int i:{0,1,2}) cin >> b[i];
    b[2]++;
    
    for (int i:{1,0}) if (b[i+1]>a[i])
        b[i+1]-=a[i], b[i]++;
    
    for (int i:{0,1,2}) cout << b[i] << " ";
}