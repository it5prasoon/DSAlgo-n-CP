// find Largest sum contiguous Subarray [VVV. IMP]


#include<bits/stdc++.h>
#include<climits>
using namespace std;

// Kadane's algorithm
void subarray_largest_sum(int a[], int n) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i=0; i<n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    cout << max_so_far << endl;

}


int main() {
    int n; cin >> n;
    int a[n];

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    subarray_largest_sum(a, n);
    return 0;
}