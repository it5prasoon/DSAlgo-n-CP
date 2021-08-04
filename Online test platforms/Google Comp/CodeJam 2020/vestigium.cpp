#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    for(int l=0;l<t;l++)
    {
        int n;
        cin >> n;
        vector<set<int> > rows(n);
        vector<set<int> > cols(n);
        
        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                rows[i].insert(x);
                cols[j].insert(x);
                
                if(i==j)
                    curr+=x;
            }
        }
        int n1=0;
        int n2=0;
        for(int i=0;i<n;i++){
            if(rows[i].size() != n) 
                n1++;
            if(cols[i].size() != n)
                n2++;
        }
        cout<<"Case #"<<l+1<<": "<<curr<<" "<<n1<<" "<<n2<<endl;
    }
    return 0;
}