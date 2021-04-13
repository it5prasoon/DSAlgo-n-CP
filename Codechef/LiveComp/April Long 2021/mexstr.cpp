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
#define foit(v) for (auto x: v) { cout << x; }
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}

using namespace std;
constexpr int MAXN = (int) 1e6;
int store_a[MAXN+2],store_b[MAXN+2];
int num_a[MAXN],num_b[MAXN];

ll min(ll x,ll y){
    if(x<y){
        return x;
    }
    return y;
}

void solve() {

    string s;
    cin>>s;
    int n = s.length();

    int last_pos = -1;

    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            for (int j=last_pos+1; j<=i; ++j) 
                num_a[j] = i;
            last_pos = i;
        }
    }

    for(int i=last_pos+1;i<n;++i) {
        num_a[i] = n;
    }

    if(num_a[0]==n) {
        cout<<"0"<<endl;
        return;
    }


    last_pos = -1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='1') {
            // cout<<"checkpoint";
            for(int j =last_pos+1; j<=i; ++j) 
                num_b[j] = i;
            last_pos = i;
        }
    }

    for (int i=last_pos+1;i<n;++i) {
        num_b[i] = n;
    }

    store_a[n] = store_a[n+1] = 0;
    store_b[n] = store_b[n+1] = 0;

    for(int i=n-1;i>=0;--i) {
        store_a[i] = store_a[i+1];
        if(s[i]=='0' && num_b[i]<n) store_a[i]=max(store_a[i],store_a[num_b[i]+1]+1);
        if(s[i]=='1' && num_a[i]<n) store_a[i]=max(store_a[i],store_a[num_a[i]+1]+1);
        store_b[i] = store_b[i+1];
        if(num_b[i]<n) store_b[i]=max(store_b[i],store_a[num_b[i]+1]+1);
    }


    int len = store_b[0] + 1;
    int current = num_b[0]+1;
    string ans = "1";
    for(int i=1; i<len; ++i) {
        if(current>=n) {
            ans.push_back('0');
            continue;
        }

        if(num_a[current] >= n) {
            ans.push_back('0');
            current = num_a[current]+1;
            continue;
        }

        if (store_a[num_a[current]+1]<len-i-1) {
            ans.push_back('0');
            current = num_a[current] +1;
        } else {
            ans.push_back('1');
            current = num_b[current] + 1;
        }
    }

cout<<ans<<endl;
}

int32_t main(){
    IOS
    int t; cin>>t;
    while(t--){
      solve();
    }
    return 0;
}

