// find duplicate in an array of N Integers
#include<bits/stdc++.h>

using namespace std;

// 1 3 4 7 3 1 4 in
// 1 3 4 out
void solve(int a[], int n) {
    int count=0;

    for(int i=0; i<n; i++) {
        a[a[i] % n] = a[a[i] % n] + n;
    }

    for (int i=0; i<n; i++) {
        if(a[i] >= n*2) {
            cout << i << " ";
        }
    }
    cout << endl;


}


int main() {
    int n; cin >> n;
    int a[n];

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    solve(a, n);

    return 0;
}