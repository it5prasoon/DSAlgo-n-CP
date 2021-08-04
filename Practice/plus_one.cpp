#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> increment(vector<int> a, int n) {        
        a[n-1] += 1;
        int carry = a[n-1]/10;
        a[n-1] = a[n-1] % 10;
    
        for (int i=n-2; i>=0; i--)
        {
            if (carry == 1)
            {
               a[i] += 1;
               carry = a[i]/10;
               a[i] = a[i] % 10;
            }
        }
    
        if (carry == 1)
          a.insert(a.begin(), 1);
          
        
    	return a; 
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  