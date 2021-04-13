#include<bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ull f(ull x, ull y, ull z){
  return (x&z)*(y&z);
}

void solve(){
  ull x, y, l, r;
  cin >> x >> y >> l >> r;

  ull F = f(x, y, x|y);
  ull z;
  for (z = l; z <= r; ++z){
    cout << z << ':' << f(x, y, z) << endl;
  }

  cout << z << ' ' << F <<  endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;

  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}