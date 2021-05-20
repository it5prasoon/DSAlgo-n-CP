#include <bits/stdc++.h>

using namespace std;

void rearrange(long long a[], int n) {
    int j=0;
    for(int i=0; i<n; i++) {
        if(a[i] < 0) {
            if (i!=j) 
                swap(a[i], a[j]);
            j++;
        }
    }

    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}

int main() {
    int n; cin>>n;
    long long a[n];

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    rearrange(a, n);

    return 0;
}