// Keep it simple
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define fe first
#define se second
#define double long double
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define last(x)  prev(x.end())
#define PP(x) cout << (x) << " "
#define PS(x) for(auto it: x)cout << it <<" "; cout << endl;
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
void PV(vi v) { for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void op() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a, int b);
int lcm(int a, int b);
bool isPrime(int n);
int powerModulo(int x, int n, int m);
void seive(int n);
int max(int a, int b); 
int min(int a, int b); 

// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 2e5 + 10;



int32_t main() {
    lets_go
    // op();

    int t;
    cin >> t;

    while (t--) {
        int n, h;
        cin >> n >> h;
        int max = INT_MIN;
        int s_max = INT_MIN;

        vector<int> a;
        int x;
        for (int i=0; i<n; i++) {
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());

        max = a[n-1];
        s_max = a[n-2];

        int cnt=0;
        cnt=h/(max+s_max);
        h-=(cnt*(max+s_max));

        if(cnt<1){
            while(h>0){
                h-=max;
                cnt++;
                if(h<=0){
                    cout<<cnt<<endl;
                    break;
                }
                h-=s_max;
                cnt++;
                if(h<=0){
                    cout<<cnt<<endl;
                    break;
                }
            }
            continue;
        }

        cnt*=2;

        if(h<=0){
            cout<<cnt<<endl;
            continue;
        }

        while(h>0){
            h-=max;
            cnt++;
            if(h<=0){
                cout<<cnt<<endl;
                break;
            }
            h-=s_max;
            cnt++;
            if(h<=0){
                cout<<cnt<<endl;
                break;
            }
        }

    }

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

int max(int a, int b) {
    return ((a>b)? a : b);
}

int min(int a, int b) {
    return ((a<b)? a : b);
}

