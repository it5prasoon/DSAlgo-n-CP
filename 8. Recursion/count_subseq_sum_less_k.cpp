#include <bits/stdc++.h>
using namespace std;


int count_subsequence(vector<int> v, int i, int product, int K)
{
    if(i >= v.size() && 0 <= product && product < K)
        return 1;
        
    if(i >= v.size() || product >= K)
        return 0;

    return count_subsequence(v, i + 1, product, K) + count_subsequence(v, i + 1, product < 0 ? v[i] : product*v[i], K);
}

int main() 
{
    vector<int> v{1, 2, 3, 4};
    int K = 10;
    cout << count_subsequence(v, 0, -1, K) << endl;
    
    return 0;
}