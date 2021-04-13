#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(long long i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define um unordered_map 
#define foit(v) for (auto x: v) { cout << x; }
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}

using namespace std;

int32_t main(){
    int t; cin>>t;

    while (t--) {
        ll n;
        cin>>n;
        ll height = n/4;
        ll extra = n%4;
        ll a,b,c,d,e;

        a=b=c=d=e=0;

        if(extra == 1)
        {
            d=1;
        }
        else if(extra == 2)
        {
            c=2;
        }
        else if(extra ==3 )
        {
            c=2;
            b=1;
        }
        if(height >0)
        {
            a += (height*4); 
            e = (4-extra)*4; 
        }
        ll v = (a*11)+(b*15)+(c*18)+(d*20)+e;
        cout<< v <<endl;
    }   
    return 0;
}