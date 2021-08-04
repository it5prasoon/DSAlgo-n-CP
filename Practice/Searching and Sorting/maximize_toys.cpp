#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        sort(arr.begin(), arr.end());
        
        int sum = 0, ans = 0;
        for(int i=0; i<N; i++) {
            sum = sum + arr[i];
             if(sum > K)
                break;
            ans++;
        }
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    }
    return 0;
} 