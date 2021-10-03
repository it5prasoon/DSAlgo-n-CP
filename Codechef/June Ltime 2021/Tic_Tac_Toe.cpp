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
#define loop(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define PP(x) cout << (x) << " "
#define INF 1000000000000000000
#define PS(x) for(auto it: x)cout << it <<" "; cout << endl;
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define lets_go ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
void PV(vi v) { for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i] << " " ; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < (int)v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void op() {
// #itmpdef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif
}
 
// <=================================================================================================================================
// <=================================================================================================================================
const int M = 1e9 + 7;
const int IM = 1e18 + 37;
const int N = 2e5 + 10;

string res = "Draw";

string binaryToe(int n, int m , int k) {
    int x[n*m+1],y[n*m+1];

    loop(i,n*m)
        cin>>x[i+1]>>y[i+1];   

    int l = 1, r = n*m;

    int steps=INF;

    int mul = (n+2)*(m+2);

    while(l<=r){

        int mid = l + (r-l)/2;
        vector<vector<int>>st(n+5, vector<int>(m+5,0));
        for(int i=1;i<=mid;i++){
            if(i&1)st[x[i]][y[i]]=1;
            else st[x[i]][y[i]]=2;
        }

        int tmp = 0;
        vvi column(n+2, vi(m+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(st[i][j]==1)column[i][j]=column[i+1][j]+1;
                else column[i][j]=0;
            }
        }

        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(column[i][j]>=k)column[i][j]=column[i][j+1]+1;
                else column[i][j]=0;
                if(column[i][j]>=k)tmp=1;
            }
        }

        column.clear();
        column.resize(n+2, vi(m+2,0));


        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(st[i][j]==2)column[i][j]=column[i+1][j]+1;
                else column[i][j]=0;
            }
        }

        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(column[i][j]>=k)column[i][j]=column[i][j+1]+1;
                else column[i][j]=0;
                if(column[i][j]>=k)tmp=2;
            }
        }

        if(tmp==0){
            l=mid+1;
        } else{
            if(mid<steps){
                steps=mid;
                if(tmp==1)
                    res="Alice";
                else 
                    res="Bob";
            }
            r=mid-1;
        }
    }

    return res;
}
void codechef()
{    
    int n, m, k;
    cin >> n >> m >> k;
    cout<<binaryToe(n, m, k);
    Br;
}
 
int32_t main() {
   lets_go
//   op();
 
   int t;
   cin >> t;
 
   while (t--) {
      codechef();
   }
   
   return 0;
}
