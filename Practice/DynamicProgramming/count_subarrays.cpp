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
    ll n; cin >> n;
    vi a(n); foin(a);

    int count=n;
    int len = 1;

    for (int i=0; i < n-1; ++i) {
        if(a[i] <= a[i+1]) {
            len++;
        } else {
            count += (((len - 1) * len) / 2);
            len = 1;
        }
    }

    if (len > 1)
        count += (((len - 1) * len) / 2);
  
    cout << count << endl;

}

int32_t main(){
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}