#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(long long i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define um unordered_map 
#define foit(x,v) for (auto x: v) 
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}
// bitset<MAX> bit1, bit2, bit3; 

using namespace std;

bool checkEqual(vector<string> &v) {
  bool uniqueElt = true;
  string first = *v.begin();
  for(auto x: v) {
      if(x != first) {
          uniqueElt = false;
          return false;
      }
  }
  return true;
}

int checkCommon(vector<char> &v, vector<char> &k) {
    set<char> common(v.begin(), v.end());
    int count=0;

    foit(x, k) {
      if (common.find(x) != common.end()) {
        count++;
      }
    }
    return count;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
        ll n; cin >> n;

        map<string,vector<char> > store;
        string str;


        fo(i,n) {
          cin >> str;
          store[str.substr(1)].pb(str[0]);
        }

        int count = 0;

        foit(i,store) {
          foit(j, store) {
            if (i.first!=j.first) {
              int counter = checkCommon(i.second, j.second);
              count+=(i.second.size()-counter)*(j.second.size()-counter);
            }
          }
        }
        cout << count <<endl;
      }
          
    return 0;
}