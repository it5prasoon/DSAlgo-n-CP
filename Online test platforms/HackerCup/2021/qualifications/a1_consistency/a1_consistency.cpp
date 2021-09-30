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

int32_t main() {
    lets_go

    op();

    int t;
    cin >> t;
    int c=1;
    int consonant = 0, vowel = 0;
    unordered_map<char, int> um;
    unordered_map<char, int> um2;
        
    while (t--) {

        string s;
        cin >> s;
        vowel = 0; 
        consonant = 0;

        um.clear();
        um2.clear();

      
        for (int i = 0; i < s.size(); i++){  
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                um[s[i]]++;
                vowel += 1;
            }
            else {
                um2[s[i]]++;
                consonant += 1;
            }
        }

        int maximum_count = 0, res = -1;
        for (auto it : um) {
            if (maximum_count < it.second)
            {
                res = it.first;
                maximum_count = it.second;
            }
        }

        int maximum_count2 = 0, res1 = -1;
        for (auto it : um2) {
            if (maximum_count2 < it.second)
            {
                res1 = it.first;
                maximum_count2 = it.second;
            }
        }

        cout << "Case #" << c << ": " << min(consonant + 2 * (vowel - maximum_count), vowel + 2 * (consonant - maximum_count2)) << endl;
        c++;
   }

   return 0;
}