// Example 1:
// Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
// C++ program to merge overlapping Intervals in
// O(n Log n) time and O(1) extra space.
#include<bits/stdc++.h>
using namespace std;

struct Interval
{
	int s, e;
};

bool mycomp(Interval a, Interval b)
{ return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)
{
	sort(arr, arr+n, mycomp);

	int index = 0; 
	for (int i=1; i<n; i++)
	{
		if (arr[index].e >= arr[i].s)
		{
			arr[index].e = max(arr[index].e, arr[i].e);
			arr[index].s = min(arr[index].s, arr[i].s);
		}
		else {
			index++;
			arr[index] = arr[i];
		}
	}

	cout << "\n The Merged Intervals are: ";
	for (int i = 0; i <= index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

int main()
{
	Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}
