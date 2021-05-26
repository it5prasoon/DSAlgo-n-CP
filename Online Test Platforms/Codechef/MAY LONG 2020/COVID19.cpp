#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int32_t main(){
    IOS
    int t; cin>>t;
    while(t--){
        ll n,min; cin>>n;
        vi v;
        fo(i,n){
            int x;
            cin>>x;
            v.pb(x);
        }
        
       vi m;
       int c;
       for(int i=0;i<n-1;i++){
           c=1;
           if(c==n){
               m.pb(c);
               break;
           }
           for(int j=i+1; j<n;j++){
               if(v[j]-v[j-1]<=2){
                   c++;
                   m.pb(c);
               }
               else{
                   break;
               }
           }
       }
    if(!m.empty()) 
    cout<<*min_element(m.begin(),m.end())<<" "<<*max_element(m.begin(),m.end())<<endl;
    else
    cout<<1<<" "<<1<<endl;

       
       
       

    }
    return 0;
}