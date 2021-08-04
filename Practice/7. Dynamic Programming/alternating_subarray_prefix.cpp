#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(long long i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define um unordered_map 
#define foit(v) for (auto x: v) { cout << x; }
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}
#define foin(v) for(auto it = v.begin(), end = v.end(); it != end; ++it) { std::cin >> *it;}

using namespace std;

void solve() {
    ll n; cin>>n;
    vi a(n);
    vi dp(n);

    foin(a);

    dp[n-1]=1;
    for (int i = n-2; i>=0; i--) {
        if (a[i]*a[i+1] < 0) {
            dp[i] = dp[i+1] + 1;
        } else {
            dp[i] = 1;
        }
    }

    for (int i=0; i<n; i++) {
        cout<< dp[i]<<" ";
    }

    cout<<endl;
    // foit(dp);

}

int32_t main(){
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}