#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int findMaximum(int arr[], int n){
        int l=0;
        int r=n-1;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
    
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1]) 
                return mid;
    
            if(arr[mid] < arr[mid+1] && arr[mid] > arr[mid - 1])
                l = mid+1;
            
            if(arr[mid] > arr[mid+1] && arr[mid] < arr[mid - 1])
                r = mid-1;
        }
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        Solution ob;
        int found = arr[ob.findMaximum(arr,N)];
        cout<<found<<endl;
    }
}
