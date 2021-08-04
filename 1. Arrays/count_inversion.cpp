// Modification of merge sort example

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int merge(long long arr[], long long temp[], long long start, long long mid, long long end)
    {
    	long long i, j, k;
    	long long inv_count = 0;
    
    	i = start; 
    	j = mid; 
    	k = start; 
    	while ((i <= mid - 1) && (j <= end)) {
    		if (arr[i] <= arr[j]) {
    			temp[k++] = arr[i++];
    		}
    		else {
    			temp[k++] = arr[j++];
    			inv_count = inv_count + (mid - i);
    		}
    	}
    
    	while (i <= mid - 1)
    		temp[k++] = arr[i++];
    
    	while (j <= end)
    		temp[k++] = arr[j++];
    
    	for (i = start; i <= end; i++)
    		arr[i] = temp[i];
    
    	return inv_count;
    }
    
    
    long long int _mergeSort(long long arr[], long long temp[], long long start, long long end)
    {
    	long long mid, inv_count = 0;
    	if (end > start) {
    		mid = (end + start) / 2;
    
    		inv_count += _mergeSort(arr, temp, start, mid);
    		inv_count += _mergeSort(arr, temp, mid + 1, end);
    		inv_count += merge(arr, temp, start, mid + 1, end);
    	}
    	return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
	    return _mergeSort(arr, temp, 0, N - 1);
    }

};

int main() {
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
