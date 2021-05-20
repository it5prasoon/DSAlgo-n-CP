#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false)
#define pb(a) push_back(a)
#define ll long long
using namespace std;

int32_t main()
{
    sync;
    cin.tie(0);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int a[n];

        for (int j = 0; j < n; j++)
            cin >> a[j];

        int pre = -1, pre_pre = -1;
        long long sum = 0ll;

        for (int j = 0; j < n; j++)
        {
            if (a[j] % 4 == 0)
            {
                sum += j + 1;
                pre_pre = pre;
                pre = j;
            }

            else if (a[j] % 2 == 0)
            {
                if (pre != -1)
                {
                    sum += j - (j - pre - 1);
                }

                pre_pre = pre;
                pre = j;
            }

            else
            {
                if (pre != -1 && pre_pre != -1)
                {
                    if (a[pre] % 4 == 0)
                        sum += (j + 1);
                    else
                    {
                        sum += (j + 1) - (pre - pre_pre);
                    }
                    
                }

                else if (pre != -1 && pre_pre == -1)
                {
                    if (a[pre] % 4 == 0)
                        sum += j + 1;
                    else
                    {
                        sum += (j - pre);
                    }
                    
                }
                
                else
                {
                    sum += j + 1;
                }
                
            }
            
        }

        cout << sum << endl;
    }
}