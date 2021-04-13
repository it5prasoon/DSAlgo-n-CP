#include<iostream>
#include<cmath>
using namespace std;
#define ll long long 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,z,l,r;
        cin>>x>>y>>l>>r;
        z=x|y;
        int x1=min(x,y);
        int x2= log((max(x,y)))+1;
        
        if(x1==0)
            cout<<0<<endl;

        else if(z<=r)
            cout<<z<<endl;
        
        else
        {
            cout<<powl(2,x2) - 1<<endl;
        }
        

    //     else
    //     {
    //         x1=max(x,y);
    //         int x2=log(x1)+1;
    //         //cout<<x2;
    //         ll p=powl(2,x2)-1;
            
    //         if(((p|x && (p|y) )||(r|x &&(r|y))))
    //             cout<<p<<endl;     
    // }   
   }
    return 0;
}