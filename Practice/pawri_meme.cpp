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
    string s;
    cin >> s;

    ll n = s.length();

    for (ll i = 0; i + 4 < n; i++) {
        if(s.substr(i,5) == "party") {
            s.replace(i,5,"pawri");
        }
        else {
            continue;
        }
    }
    cout << s << endl;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}