#include<bits/stdc++.h>


//====================Written by prasoon================//

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(long long i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vl vector<long long>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define um unordered_map 
#define mp make_pair
#define setd set<long long>
#define vps vector<pair<long long, long long>>
#define vp vector<vector<pair<long long, long long>>>
#define foit(v) for (auto x: v) { cout << x; }
#define foin(v) for(auto it = v.begin(), end = v.end(); it != end; ++it) { std::cin >> *it;}
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}

using namespace std;

ll min(ll x,ll y){
    if(x<y){
        return x;
    }
    return y;
}

vp solve(ll n, ll m, ll k) {
  // Input 
  vl g(n+1);
  fo (i, n) {
    cin>>g[i+1];
  }

  vp store(n+1);
  fo(i, m) {
    ll u,v,d;
    cin>>u>>v>>d;
    store[u].pb(mp(i,d));
    store[v].pb(mp(i,d));
  }

  vp dp(n+1);
  dp[0].pb(mp(0,0));

  // Logic Starts
  Fo(i,1,n) {
    vps tmp;
    tmp.insert(tmp.end(), all(dp[i-1]));

    ll current = 0, mask = 0;
    setd s;

    for (ll j=i; j>=2; j--) {
      current+=g[j];
      mask^=1LL<<j;

      for (auto & [idx,w]: store[j]) {
        if (s.count(idx)) {
          current+=w;
        } else {
          s.insert(idx);
        }
      }

      if (j>1) {
        for (auto & [val, prev_mask]: dp[j-2]) {
          tmp.pb(mp(val+current, mask^prev_mask));
        }
      } else {
        tmp.pb(mp(current, mask));
      }
    }

    sortall(tmp);
    reverse(all(tmp));
    setd ansSet;

    ll already = 0;
    for(ll j=0; j<tmp.size() && already<k; j++) {
      if(ansSet.count(tmp[j].second)) continue;
      dp[i].pb(tmp[j]);

      already++;
      ansSet.insert(tmp[j].second);
    }
  }
  return dp;
}

void printSolution() {
  ll n,m,k;
  cin >> n >> m >> k;
  vp v = solve(n, m, k);
  fo(i, k) {
      cout << v[n][i].first<<" ";
  }
  cout<<endl;
}


int32_t main(){
    IOS
    int t; cin>>t;
    while(t--){
      printSolution();
    }
    return 0;
}

