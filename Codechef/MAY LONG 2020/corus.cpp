#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 

int32_t main(){
    ll t,i,n,q,c,j,k,unique,count,arr[100000],m,msize;
    string s;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>q;
        cin>>s;
        sort(s.begin(),s.end());
        for(j=0;j<q;j++){
            cin>>c;
            unique=0;
            if(j==0){
                for(k=0,m=0,count=1;k<s.size();m++){
                    count = s.rfind(s[k]) - k + 1;
                    arr[m]=count;
                    k=k+count;
                    if(count>=c){
                        unique = unique + count - c;
                    }
                }
                msize=m;
            }
            else{
                unique=0;
                for(m=0;m<msize;m++){
                    if(arr[m] > c){
                        unique=unique + arr[m] - c;
                    }
                }
            }
            cout<<unique<<endl;
        }
    }
}
