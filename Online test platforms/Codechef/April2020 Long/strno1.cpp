#include <bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, k;
        cin >> x >> k;
        int sum = 0;

       while (x % 2 == 0)  
        {    
            x = x/2; 
            sum++; 
        }  
       // cout<<sum<<" ";
        for (int i = 3; i * i <= x; i += 2)
        {
            if (x % i == 0)
            {
                while (x % i == 0)
                {
                    x = x / i;
                    sum++;
                }
            }
        }
        // cout<<sum<<" ";
        if (x > 2)
        {
            sum++;
        }
      //  cout << sum<<" ";
        if (k <= sum)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}