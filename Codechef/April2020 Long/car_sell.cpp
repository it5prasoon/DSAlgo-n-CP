#include <bits/stdc++.h>
#define M 1000000007
#define ll long long
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> p;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            p.push_back(x);
        }

        sort(p.begin(), p.end(), greater<int>());
        ll sum = p[0];
        for (int i = 1; i < n; i++)
        {
            // sum = sum + p[i] - i;
            if (p[i] - i <= 0)
            {
                sum = sum % M;
            }
            else
            {
                sum = (sum + p[i] - i) % M;
            }
        }
        cout << sum << endl;
    }

    return 0;
}