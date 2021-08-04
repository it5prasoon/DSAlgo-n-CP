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

string printRandomString(int n, int k)
{
    string s = "";
    for (int i = 0; i < k; i++) {
        s += 'a' + i;
        for (int j = i+1; j < k; j++) {
            s += 'a' + i;
            s += 'a' + j;
        }
    }
      
    while (int(s.length()) < n) s += s;
        s.resize(n);
    return s;
}

void solve() {
    int n, k; cin >> n >> k;

    cout << printRandomString(n, k);
}

int32_t main(){
    solve();
    return 0;
}