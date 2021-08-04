#include<bits/stdc++.h>

using namespace std;


void rotate(int a[], int n) {
    // 1 2 3 4 5
    // 5 1 2 3 4

    // int b[n+1];
    // b[n] = 0;

    // for (int i=1; i<n; i++) {
    //     b[i] = a[i-1];
    // }

    // b[0] = a[n-1];

    // for (int i=0; i<n; i++) {
    //     cout << b[i];
    // }

    int x = a[n-1];
    for(int i=n-1; i>0; i--) {
        a[i] = a[i-1];
    }
    a[0] = x;

    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }

}

int main() {
    int n; cin >> n;
    int a[n];

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    rotate(a, n);

    return 0;
}