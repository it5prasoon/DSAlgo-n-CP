#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        vector<int> y;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
                y.push_back(i);
        }
        int c1 = 0;
        for (int i = 0; i < y.size() - 1; i++)
        {
            if ((y[i + 1] - y[i]) < 6)
            {
                c1++;
            }
        }
        if (c1 > 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}