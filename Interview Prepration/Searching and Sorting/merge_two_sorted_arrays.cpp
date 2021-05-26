#include <bits/stdc++.h>
using namespace std;


// Time Complexity = O((n+m)log(n+m))
// Space Complexity = O(1)

void merge(int arr1[], int arr2[], int n, int m)
{
	int i = 0, j = 0, k = n - 1;
	while (i <= k and j < m) {
		if (arr1[i] < arr2[j])
			i++;
		else {
			swap(arr2[j++], arr1[k--]);
		}
	}

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
}

// Driver Code
int main()
{

	int ar1[] = { 1, 5, 9, 10, 15, 20 };
	int ar2[] = { 2, 3, 8, 13 };
	int m = sizeof(ar1) / sizeof(ar1[0]);
	int n = sizeof(ar2) / sizeof(ar2[0]);
	merge(ar1, ar2, m, n);

	cout << "After Merging \nFirst Array: ";
	for (int i = 0; i < m; i++)
		cout << ar1[i] << " ";
	cout << "\nSecond Array: ";
	for (int i = 0; i < n; i++)
		cout << ar2[i] << " ";
	return 0;
}
