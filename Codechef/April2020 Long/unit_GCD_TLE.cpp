#include<bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)

using namespace std;

inline bool coprime(int a, int b)
{
    if (__gcd(a, b) == 1)
        return true;
    else
    {
        return false;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool ar[n + 1];
        for (int i = 0; i < n + 1; i++)
            ar[i] = false;

        vector<vector<int>> v;
        vector<int> temp;

        temp.pb(1);
        v.pb(temp);
        for (int i = 2; i <= n; i++)
        {
            if (ar[i] == true)
                continue;
            int j = i;
            int k = 1;
            int count = 0;
            while (true)
            {
                j = i * k;
                if (j > n)
                    break;
                if (ar[j] == true)
                {
                    k++;
                    count++;
                    continue;
                }
                ar[j] = true;
                if (k - 1 >= v.size())
                {
                    vector<int> v1;
                    v1.pb(j);
                    v.pb(v1);
                }
                else
                {
                    if (k == 1)
                    {
                        v[0].pb(j);
                    }
                    else
                    {
                        bool done = false;
                        for (int l = 1; l < v.size(); l++)
                        {
                            for (int m = 0; m < v[l].size(); m++)
                            {
                                if (coprime(v[l][m], j))
                                {
                                    if (m == v[l].size() - 1)
                                    {
                                        v[l].pb(j);
                                        done = true;
                                    }
                                    continue;
                                }
                                else
                                    break;
                            }
                            if (done)
                                break;
                        }
                    }
                }
                k++;
            }
        }
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].size() << " ";
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
