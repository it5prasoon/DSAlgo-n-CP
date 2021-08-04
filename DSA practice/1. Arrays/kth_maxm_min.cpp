// Find the "Kth" max and min element of an array 
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin>>n>>k;
    int a[n];

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    cout << "Kth Maximum: "<< a[0+k] << endl;
    cout << "Kth Minimum: "<< a[n-k-1] << endl;
    

    return 0;
}