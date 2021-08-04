#include<bits/stdc++.h>
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
#define vi vector<int>
#define viii vector<tuple<int,int,int>>
#define F first
#define S second
#define pt(a) for(auto it:a)cout<<*it<<" ";cout<<endl; 
                                        


const int mod = 1000000007;
//====================================
ll n,k;
vi p, swp;

void swapall(int i, int j, int k){
    int a = p[i];
    int b = p[j];
    int c = p[k];
    p[i] = c;
    p[j] = a;
    p[k] = b;
    swp[a] = j;
    swp[b] = k;
    swp[c] = i;
}

bool ok(){
    for (int i = 0; i < n; ++i){
    if (p[i] != i)  return false;
  }
  return true;
}

void solution(){
    cin>>n>>k;
    p.resize(0); p.resize(n);
    swp.resize(0); swp.resize(n);
       for (auto& x : p) {
            cin >> x;
                --x;
         }
        for (int i=0; i<n; ++i){
            swp[p[i]] = i;
        }

        int srt = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if (p[i]>p[j]) srt++;
            }
        }
        if(srt&1){
            cout<<"-1"<<endl;
            return;
        }
        int count = 0;

        viii sol;
        for(int i=0; i<n; ++i){
            if(p[i] ==i ){
                continue;
            }
            int j = swp[i];
            if (j>=n){
                cout<<"-1"<<endl;
                return;
            }
            if(abs(j-i) == 1){
            swapall(i, i+1, i+2);
            swapall(i, i+1, i+2);
            count++;
            sol.pb(make_tuple(i, i+1, i+2));
            sol.pb(make_tuple(i,i+1,i+2));
        }
        else{
            swapall(i,j-1,j);
            sol.pb(make_tuple(i,j-1,j));
        }
        count++;
        }
        if(!ok() || count >k){
            cout<<"-1"<<endl;
            return;
        }
        cout<<count<<endl;
        for(auto x: sol){
            cout<<get<0>(x)+1 << ' '<<get<1>(x)+1 <<' '<<get<2>(x)+1<<endl;
        }        
}



int32_t main()
{
	IOS;
    ll t; cin>>t;
    while(t--){
        solution();

    }
	return 0;
}

