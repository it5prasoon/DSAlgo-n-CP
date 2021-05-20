// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
#include <bits/stdc++.h>

using namespace std;


void sort012(int a[], int n) {
    int cnt0=0, cnt1=0, cnt2=0;

    for (int i=0; i<n; i++) {
        switch(a[i]) {
            case 0:
                cnt0++;
                break;
            case 1:
                cnt1++;
                break;
            case 2:
                cnt2++;
                break;
        }

    }

    int i=0;
    while(cnt0>0) {
        a[i++] = 0;
        cnt0--;
    }
    while(cnt1>0) {
        a[i++] = 1;
        cnt1--;
    }
    while(cnt2>0) {
        a[i++] = 2;
        cnt2--;
    }

    for (int j=0; j<n; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
}

int main() {
    int n; cin>>n;
    int a[n];

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort012(a, n);
   
    return 0;
}