// Keep it simple
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define double long double
#define fo(i,n) for(int i=0;i<n;i++)
#define foi(i, n) for (int i = n - 1; i >= 0; i--)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define last(x)  prev(x.end())
#define PP(x) cout << (x) << " "
#define PS(x) for(auto it: x)cout << it <<" "; cout << endl;
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
void PV(vi v) { for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vpii v) {for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void op() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int min(int x, int y) { return ((x < y) ? x : y); }
int max(int x, int y) { return ((x > y) ? x : y); }
void readvec(vector<int> &v, int n) { for(int i=0; i<n; i++) { int x; cin >> x; v.push_back(x); } }
int gcd(int a, int b);
int lcm(int a, int b);
bool isPrime(int n);
int powerModulo(int x, int n, int m);
void seive(int n);

// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 2e5 + 10;



int32_t main() {
    lets_go
    // op();


    int n; cin >> n;
    string s;
    cin >> s;

    vector<vi> cnt(3, vector<int>(3));

    vector<vector<vi>> at(3, vector<vector<int>>(3));

    fo(i, 3*n) {
        cnt[i / n][(int) (s[i] - 'A')] += 1;
        at[i/n][(int) (s[i] - 'A')].push_back(i);
    }

    for (int AB = 0; AB <= cnt[0][0]; AB++) {
    int AC = cnt[0][0] - AB;
    int BC = cnt[2][2] - AC;
    int BA = cnt[0][1] - BC;
    int CA = cnt[2][0] - BA;
    int CB = cnt[0][2] - CA;
    if (AC < 0 || BC < 0 || BA < 0 || CA < 0 || CB < 0) {
      continue;
    }


    if (AB + BA != cnt[1][2] || AC + CA != cnt[1][1] || BC + CB != cnt[1][0]) {
      continue;
    }

    string ret(3 * n, '-');
    for (int i = n; i < 2 * n; i++) {
      if (s[i] == 'A') {
        if (BC > 0) {
          ret[at[0][1].back()] = '1'; at[0][1].pop_back();
          ret[at[2][2].back()] = '1'; at[2][2].pop_back();
          ret[i] = '1';
          BC -= 1;
          continue;
        }
        if (CB > 0) {
          ret[at[0][2].back()] = '2'; at[0][2].pop_back();
          ret[at[2][1].back()] = '2'; at[2][1].pop_back();
          ret[i] = '2';
          CB -= 1;
          continue;
        }
      }
      if (s[i] == 'B') {
        if (AC > 0) {
          ret[at[0][0].back()] = '3'; at[0][0].pop_back();
          ret[at[2][2].back()] = '3'; at[2][2].pop_back();
          ret[i] = '3';
          AC -= 1;
          continue;
        }
        if (CA > 0) {
          ret[at[0][2].back()] = '4'; at[0][2].pop_back();
          ret[at[2][0].back()] = '4'; at[2][0].pop_back();
          ret[i] = '4';
          CA -= 1;
          continue;
        }
      }
      if (s[i] == 'C') {
        if (BA > 0) {
          ret[at[0][1].back()] = '5'; at[0][1].pop_back();
          ret[at[2][0].back()] = '5'; at[2][0].pop_back();
          ret[i] = '5';
          BA -= 1;
          continue;
        }
        if (AB > 0) {
          ret[at[0][0].back()] = '6'; at[0][0].pop_back();
          ret[at[2][1].back()] = '6'; at[2][1].pop_back();
          ret[i] = '6';
          AB -= 1;
          continue;
        }
      }
      assert(false);
    }
    cout << ret << '\n';
    return 0;
  }
  assert(false);
    
        
    return 0;

}

int gcd(int a, int b) { if (b==0) return a; else return gcd(b, a%b); }
int lcm(int a, int b) { return (a*b)/gcd(a,b); } 

bool isPrime(int n) {
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

int powerModulo(int x, int n, int m) {
    int res = 1;
    while (n>0) {
        if (n&1) res = (res*x)%m;
        x = (x*x)%m;
        n = n>>1;
    }
    return res;
}

void seive(int n){
    vector<bool> is_prime(n+1, true);
    for (int i=2; i<=n; i++)
        if(is_prime[i]) {
            cout << i << " ";
            for (int j=i*i; j<=n; j=j+i) is_prime[j] = false;
        }
}
