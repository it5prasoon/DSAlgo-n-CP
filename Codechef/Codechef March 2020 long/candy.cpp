#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
       int c[100000];

        for(int i=0;i<n;i++){
            c[i]=1;
        }
         for(int i=0;i<n;i++){
            if(c[i]>c[i+1]){
                c[i+1]=c[i]-k;
            }
            else
            {
                c[i+1]=c[i]+k;
            }
            
        }
        int s=0;
         for(int i=0;i<n;i++){
            s=s+c[i];
        }

        
        cout<<s<<endl;
    
    }
    return 0;
}