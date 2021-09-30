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
void solution(int res, int c);

int32_t main() {
    lets_go
    op();

    int t;
    cin >> t;
    int c=1;

    while (t--) {

        int n;
        string w;
        cin >> n;
        cin >> w;

        stack<char> s;

        int res = 0;

        // for (int i=0; i < n; i++) {
        //     if ((w[i] == 'X' && w[i+1] == 'O') || (w[i] == 'O' && w[i+1] == 'X')) {
        //         res+=1;
        //     } else if ((w[i] == 'F' && w[i+1] == 'O' && w[i-1] == 'X') || (w[i] == 'F' && w[i+1] == 'X' && w[i-1] == 'O')) {
        //         res+=1;
        //     }
        // }

        for (int i=0; i < n; i++) {
            if (w[i] == 'X' || w[i] == 'O') {

                if ( !s.empty()) {
                    if (s.top() == w[i])
                        s.pop();
                } 
                s.push(w[i]);
                // cout << s.size() << " ";
            } 
        }

        res = s.size() - 1;
        if (res == -1) {
            res = 0;
        }
        solution(res, c);
        c++;
    }
  
   return 0;
}


void solution(int res, int c) {
    cout << "Case #" << c << ": " << res << endl;
}
