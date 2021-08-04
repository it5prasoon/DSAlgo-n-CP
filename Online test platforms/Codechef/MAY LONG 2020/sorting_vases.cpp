#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);
#define gc getchar_unlocked
#define ld long double
#define PI (ld)3.1415926535897932384626
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(s) scanf("%s",&s)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define ps(s) printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define clr(x) memset(x, 0, sizeof(x))
#define vi vector<int>
#define vl vector<ll>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpl vector<pll>
#define vvi vector<vi>
#define vvl vector<vl>
#define F first
#define S second
#define take(a) for (auto& x : a) cin >> x;
#define eject(a) for(auto it=a.begin(); it!=a.end();++it) cout<<*it<<" ";cout<<endl;
const int mod = 1000000007;
//====================================

int main(){
    int T,n,m,x,y; cin >> T;
    while(T--) 
        cin>>n>>m;
        vi p;
        p.resize(0); p.resize(n);
        take(p);
        vector<pii> robotSwap;

        fo(i,m){
          cin>>x>>y;
          robotSwap.pb(mp(x,y));
          robotSwap.pb(mp(y,x));
        }
        
        int time = 0;
        int time_wait = 0;
        vi mod_p = p;

        if(m == 0){
          fo(i,n){
            mod_p = 
          }
        }





    return 0;
}