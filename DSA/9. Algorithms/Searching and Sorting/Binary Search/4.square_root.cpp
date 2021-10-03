#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int binarysearch(int k){
        int l=0;
        int r=k;
        int ans;

        if (k == 0 || k == 1)
            return k;
        
        while(r >= l ) {
            int mid = l + (r-l)/2;
    
            if (mid * mid == k)
                return mid;
    
            if(mid <= k/mid){
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int key;
        cin>>key;
        Solution ob;
        int found = ob.binarysearch(key);
        cout<<found<<endl;
    }
}
