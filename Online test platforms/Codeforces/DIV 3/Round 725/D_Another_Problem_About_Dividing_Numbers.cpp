// Keep it simple
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define int long long
#define fe first
#define se second
#define double long double
#define aint(v) v.begin(),v.end()
#define aintr(v) v.rbegin(),v.rend()
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
 
// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 2e5 + 10;

int count(int a) {
    int l = 0;
    for(int i=2;i*i<=a;i++){
        while(a%i==0){
            l++;
            a/=i;
            // cout << a << " ";
        }
    }
    l += (a != 1);
    return l;
}
 
void solve(int a, int b, int k) {
    int x, j=0, l=0;

    if (k > 60) {
        cout << "NO";
        Br;
        return;
    }

    if (k == 1 && (a % b == 0 || b % a == 0) && a != b) {
        cout << "YES";
        Br;
        return;
    }

    if(k != 1 && k <= count(a) + count(b)) {
        cout << "YES";
        Br;
    } else {
        cout << "NO";
        Br;
    }
}
 
int32_t main() {
    lets_go
    //   op();
    
    int t;
    cin >> t;
 
    while (t--) {
        int a,b,k;
        cin >> a >> b >> k;
        
        solve(a, b, k);
    }
   
   return 0;
}
