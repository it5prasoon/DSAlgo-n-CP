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

    // there are two servers 
    ll n; cin >> n;

    int ans = 0;
		for (int i = 0; i < n; i++) {
			int r;
			cin >> r;
			if (r == 1 || r == 3) {
				ans++;
			}
		}
		cout << ans << endl ;

}

int32_t main(){
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}