#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define ll long long


using namespace std;

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n,m,K;
        cin>>n>>m>>K;

        int c[n][K];
        int res[n];
        for(int i=0; i<n; i++){
            vector<int> t1(m,0);
            for(int j=0; j<K; j++){
                cin>>c[i][j];
                t1.pb(c[i][j]);
            }
            int index=0, value=0;
            for(int k=0;k<m; k++){
                if(value<=t1[k]){
                    value=t1[k];
                    index=k;
                }
            }
            res[i]=c[i][index];
        }

        for(int i=0;i<n;i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}