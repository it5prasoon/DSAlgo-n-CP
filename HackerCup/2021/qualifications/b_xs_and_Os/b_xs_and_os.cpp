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
void solution(int res, int noOfCells, int c);

int32_t main() {
    lets_go
    op();

    int t;
    cin >> t;
    int c=1;

    while (t--) {
        int res = INT_MAX, noOfCells = 0;
        map<int, int> mp;
        int n,q;
        cin >> n;

        char arr[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

       
        for (int i = 0; i < n; i++) {
            int x = 0, flag = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'O') {
                    flag = 1;
                    break;
                }
                else if (arr[i][j] == '.') {
                    x++;
                    q = j;
                }
            }
            if (!flag && res > x)
            {
                res = x;
                noOfCells = 1;
                if (res == 1)
                mp[q]++;
            }
            else if (!flag && res == x)
            {
                noOfCells++;
                if (res == 1)
                mp[q]++;
            }

        }

        for (int i = 0; i < n; i++) {
            if (!mp[i]) {
                int x = 0, flag = 0;
                for (int j = 0; j < n; j++){
                    if (arr[j][i] == 'O') {
                        flag = 1;
                        break;
                    }
                    else if (arr[j][i] == '.')
                        x++;
                }
                if (!flag && res > x){
                    res = x;
                    noOfCells = 1;
                }
                else if (!flag && res == x)
                noOfCells++;
            }
        }
        solution(res, noOfCells, c);
        c++;
    }
        
   return 0;
}


void solution(int res, int noOfCells, int c) {
    if (res == INT_MAX)
            cout << "Case #" << c << ": Impossible" << "\n";
    else
        cout << "Case #" << c << ": " << res << " " << noOfCells << "\n";
        
}
