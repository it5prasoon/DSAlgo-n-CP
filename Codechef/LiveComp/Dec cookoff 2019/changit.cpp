#include <bits/stdc++.h> 
using namespace std; 
 
int main() 
{ 
    int t,n;
   
    cin>>t;
 while(t--){
       int n,i,max=-1;
       int ar[101]={0};
       cin>>n;
       int num;
       for(i=0;i<n;i++){
          cin>>num;
           ar[num]++;
       }
       for(i=1;i<=100;i++){
          if(max<ar[i]){                 // if maximum is less then do max is equal to all the elements in the array its the shortest method.
              max=ar[i];
          } 
       }
       cout<<n-max;
   }
  return 0; 
} 