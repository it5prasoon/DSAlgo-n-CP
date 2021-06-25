// https://practice.geeksforgeeks.org/problems/410d51d667ab93f2219b15126f001f32e8bb029e/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int temp[n];
        memset(temp, -1, sizeof(temp));
        
        for(int i=0; i<n; ++i) {
            if(gallery[i] == 0) {
                temp[i] = max(temp[i], i);
                continue;
            }
            if(gallery[i] != -1) {
                int k = i+gallery[i];
                int j = i-gallery[i];
                for(int ii=j;ii<=min(n,k);++ii) {
                    temp[ii] = max(k, temp[ii]);
                }
            }
        }
        
        int count=0, i=0;
        while(i<n) {
            if(i==-1 || temp[i]==-1) {
                return -1;
            }  
            ++count;
            i=temp[i]+1;
        }
        
        return count;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}