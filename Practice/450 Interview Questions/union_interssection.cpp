// Find the Union and Intersection of the two sorted arrays.
#include <bits/stdc++.h>

using namespace std;

void printIntersection(int a[], int b[], int n, int m) {
    int i=0; int j=0;
    while(i<n && j<m) {
        if(a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            cout << b[j] << " ";
            i++;
            j++;
        }
    }
}

void printUnion(int a[], int b[], int n, int m) {
    int i=0; int j=0;
    while (i<n && j<m) {
        if(a[i] < b[j]) {
            cout << a[i++] << " ";
        } else if (a[i] > b[j]) {
            cout << b[j++] << " ";
        } else {
            cout << b[j++] << " ";
            i++;
        }
    }
    while (i < n) {
        cout << a[i++] << " ";
    }
    while (j < m) {
        cout << b[j++] << " ";
    }

}

int main() {
    int n,m; cin>>n>>m;
    int a[n], b[m];
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    // 1 5 6 8 9 10
    // 2 4 5 7 9 11

    printIntersection(a, b, n, m);
    cout << endl;
    printUnion(a, b, n, m);
    cout << endl;     

    return 0;
}