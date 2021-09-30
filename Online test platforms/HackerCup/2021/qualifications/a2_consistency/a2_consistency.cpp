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
void floydWarshallAlgo(vector<vector<int>> &arr, int n);
void solution(int res, int c);

int32_t main() {
    lets_go
    op();

    int t;
    cin >> t;
    int c=1;

    while (t--) {
        string s; cin >> s;
        int k; cin >> k;

        unordered_map<char, vector<char>> m;
        unordered_set<char> temp;

    
        for (int j = 0; j < k; j++) {
            string st; cin >> st;
            m[st[0]].push_back(st[1]);
            temp.insert(st[0]);
            temp.insert(st[1]);
        }

        for (char ch : s) {
            temp.insert(ch);
        }

        int n = temp.size(), ind = 0;
        unordered_map<char, int> nodes;
        for (char ch : temp) {
            nodes[ch] = ind++;
        }

        vector<vector<int>> g(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) g[i][i] = 0;

        for (auto itr : m) {
            for (auto k : itr.second) {
                g[nodes[itr.first]][nodes[k]] = 1;
            }
        }
        floydWarshallAlgo(g, n);

        int res = INT_MAX;
        for (char ch : temp) {
            int cnt = 0;
            bool dis = false;
            for (char c : s) {
                int arr = g[nodes[c]][nodes[ch]];
                if (arr == INT_MAX) {
                dis = true;
                break;
                }
                cnt += arr;
            }
            if (dis) continue;
            res = min(res, cnt);
        }

        solution(res, c);
        c++;
    }
  
   return 0;
}

void floydWarshallAlgo(vector<vector<int>> &arr, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (arr[i][j] > (arr[i][k] + arr[k][j])
                    && (arr[k][j] != INT_MAX
                        && arr[i][k] != INT_MAX))
                arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

void solution(int res, int c) {
    cout << "Case #" << c << ": ";
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
}
