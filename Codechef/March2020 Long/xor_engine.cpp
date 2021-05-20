#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n,q; cin>>n; cin>>q;
        vector<long> a;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        while(q--){
            int p;
            cin>>p;
            long b[100000000];

        for(int i=0;i<n;i++){
          p ^= a[i];
        }
        for(int i=0;i<n;i++){
         b[i]=p^a[i];
        }
        for(int i=0;i<n;i++){
            int res=0;
            while(b[i] > 0) {
            int cur = (b[i] & 1);
            res = res + cur;
                b[i] = (b[i] - cur)/2;
            }
            cout<<res;
        }


        }

    }
    return 0;
}