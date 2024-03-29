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

void solution(int c, string s);

int32_t main() {
    lets_go
    op();

    int t;
    cin >> t;
    int c=1;

    while (t--) {

        int n,m,a,b;
        cin >> n >> m >> a >> b;

        int len = n+m-1;
        if (len > a || len > b) {
            solution(c, "Impossible");
            c++;
            continue;
        }

        solution(c, "Possible");

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                    cout << a-len+1 << " ";
                else if (i == 0 && j == m - 1)
                    cout << b-len+1 << " ";
                else
                    cout << "1 ";
            }
            cout << endl;
        }
        c++;
    }
  
   return 0;
}


void solution(int c, string s) {
    cout << "Case #" << c << ": " << s << endl;
}
