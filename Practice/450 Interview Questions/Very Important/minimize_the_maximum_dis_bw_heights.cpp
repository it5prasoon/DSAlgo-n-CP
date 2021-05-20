// Minimise the maximum difference between heights [V.IMP]
// Given heights of n towers and a value k. 
// We need to either increase or decrease the height of every tower by k (only once) where k > 0. 
// The task is to minimize the difference between the heights of the longest and the shortest 
// tower after modifications and output this difference.
#include<bits/stdc++.h>

using namespace std;

void solve(int a[], int n, int k) {
    sort(a, a+n);
    int minEle, maxEle;
    int result = a[n-1] - a[0];

    for(int i=1; i<n; i++) {
        if (a[i] >= k) {
            maxEle = max(a[i-1]+k, a[n-1]-k);
            minEle = min(a[0]+k, a[i]-k);

            result = min(result, maxEle - minEle);
        }
    }

    cout << result << endl;
}

int main() {
    int n; cin >> n;
    int a[n], k; cin >> k;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    solve(a, n, k);

    return 0;
}