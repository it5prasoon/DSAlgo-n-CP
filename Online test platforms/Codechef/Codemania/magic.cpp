#include<bits/stdc++.h>

using namespace std;

int main(){

    long l; cin>>l;
    char s[10000000];
    cin>>s;

    long c1=0,c2=0;
    for(long i=0;i<l;i++)
    {
        if(s[i]=='a')
        {
            c1++;
        }
        else if(s[i]=='b'){
            c2++;
        }
    }
    long t = abs(c1-c2);
    cout<<t<<endl;


    return 0;
}