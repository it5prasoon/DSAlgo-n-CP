#include <iostream>                        
#include <vector>
using namespace std;

template<class T> bool almostIncreasing( const vector<T> &v )
{
   bool available = true;               
   int last = v.size() - 1;
   for ( int i = 1; i <= last; i++ )
   {
      if ( v[i] <= v[i-1] )                       
      {                                              
         if ( !available ) return false;            
         if ( i == last )  return true;             

         if ( i > 1 )                               
         {
            bool ok = ( v[i-2] < v[i-1] && v[i-1] < v[i+1] )  ||  ( v[i-2] < v[i] && v[i] < v[i+1] );
            if ( !ok ) return false;                
         }
         available = false;                     
      }
   }
   return true;
}

int main()
{
    int t; cin>>t;
    while(t--){
    int n; cin>>n;
   vector<int> v;
   int x;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            v.push_back(x);
        }
   if(almostIncreasing(v)==1){
       cout<<"TRUE"<<endl;
   }
   else{
       cout<<"FALSE"<<endl;
   }
    }
    return 0;
}