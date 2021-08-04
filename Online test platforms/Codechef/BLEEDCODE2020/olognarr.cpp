#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x; cin>>x;
        vector<int> v;
        int m;
        for(int i=0;i<n;i++){
            cin>>m;
            v.push_back(m);
        }
        int cnt;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]+v[j]==x){
                    cout<<"AVAILABLE "<<v[i]<<" "<<v[j]<<endl;
                    cnt=1;
                    break;
                }    
                else{
                cnt=0;
                continue;
            }        
            }
            if(cnt==1){
                break;
            }
        }
        if(cnt==0){
                    cout<<"NOT AVAILABLE"<<endl;
                }
    }
return 0;
}