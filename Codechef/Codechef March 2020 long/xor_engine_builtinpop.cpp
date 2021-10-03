#include<bits/stdc++.h>

using namespace std;
void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }
  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l; fastscan(l);
    
    for(int k=0;k<l;k++){
        int n,q; fastscan(n);
        fastscan(q);
        int a[100000];
       int c1=0,c2=0,c;
        for(int i=0;i<n;i++){
            fastscan(a[i]);
            c=__builtin_parity(a[i]);
            if(c==1)
            c1++;
            else
            c2++;
        }
        for(int j=0;j<q;j++){
            int p;
            fastscan(p);
            int o;
            o=__builtin_parity(p);
           
            int c3,c4;
            if(o==1){
                c3=c1;
                c4=c2;
            }
            else{
            c3=c2;
            c4=c1;
            }
       
        
        
       printf("%d %d\n",c3,c4);

            
        }
}
return 0;
}