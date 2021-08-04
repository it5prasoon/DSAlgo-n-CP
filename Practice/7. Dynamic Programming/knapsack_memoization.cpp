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
 
// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 2e5 + 10;


int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int w, int wt[], int val[], int n) { 

    // Setting value -1
    int mat[n+1][w+1];
    memset(mat, -1, sizeof(mat));
    
    if (n==0 || w == 0) {
        return 0;
    } 

    if (mat[n][w] != -1) {
        return mat[n][w];
    }


    // Choice diagram
    if (wt[n - 1] > w) {
        mat[n][w] = knapSack(w, wt, val, n - 1);
        return mat[n][w];
    }
    else {
        mat[n][w] = max(val[n - 1] + knapSack(w - wt[n - 1],wt, val, n - 1),
            knapSack(w, wt, val, n - 1));
        return mat[n][w];
    }
    
}
 
int32_t main() {
   lets_go
//   op();
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, w;
        cin >> n >> w;

        int wt[n], val[n];

        for(int i=0; i<n; i++) {
            cin >> wt[i];
        }

        for (int i=0; i<n; i++) {
            cin >> val[i];
        }

        cout << knapSack(w, wt, val, n) << endl;
    }
   return 0;
}
