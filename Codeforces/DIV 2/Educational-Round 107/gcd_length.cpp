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

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    auto getPower = [&](ll base, ll exp) {
			int res = 1;
			while (exp > 0) {
				if (exp & 1) {
					res *= base;
				}
				base *= base;
				exp /= 2;
			}
			return res;
		};
		ll x = getPower(10, a - 1);
		ll y = getPower(10, b - 1) + getPower(10, c - 1);
		cout << x << " " << y << '\n';
}

int32_t main(){
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}