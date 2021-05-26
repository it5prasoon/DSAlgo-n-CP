// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}

int first_occurence(int arr[], int n, int x) {
    int l=0;
    int r=n-1;
    int res = -1;
    
    while(l<=r) {
        int mid = l + (r-l)/2;

        if(x == arr[mid]) {
            res = mid;
            r = mid - 1;
        } 

        if(x > arr[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return res;
}

int last_occurence(int arr[], int n, int x) {
    int l=0;
    int r=n-1;
    int res=-1;
    
    while(l <= r) {
        int mid = l + (r-l)/2;
        
        if(x < arr[mid])
            r = mid - 1;
        else if(arr[mid] < x)
            l = mid + 1;
        else {
            res = mid;
            l = mid + 1;
        }
    }

    return res;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v;
    v.push_back(first_occurence(arr, n, x));
    v.push_back(last_occurence(arr, n, x));
    
    return v;
}