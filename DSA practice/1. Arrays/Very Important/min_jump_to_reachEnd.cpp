// C++ program to find Minimum
// number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
	int* jumps = new int[n];
	int min;
	jumps[n - 1] = 0;


	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] == 0)
			jumps[i] = INT_MAX;
		else if (arr[i] >= n - i - 1)
			jumps[i] = 1;

		else {
			min = INT_MAX;
			for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
				if (min > jumps[j])
					min = jumps[j];
			}
			if (min != INT_MAX)
				jumps[i] = min + 1;
			else
				jumps[i] = min; 
		}
	}

	return jumps[0];
}

int main()
{
	int arr[] = { 1, 3, 6, 1, 0, 9 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Minimum number of jumps to reach"
		<< " end is " << minJumps(arr, size);
	return 0;
}
