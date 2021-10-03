#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int binarysearch(int arr[], int n, int k){
        int l=0;
        int r=n-1;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
    
            if(arr[mid] == k) 
                return mid;
    
            if(arr[mid] < k)
                l = mid+1;
            else
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
        int key;
        cin>>key;
        Solution ob;
        int found = ob.binarysearch(arr,N,key);
        cout<<found<<endl;
    }
}
