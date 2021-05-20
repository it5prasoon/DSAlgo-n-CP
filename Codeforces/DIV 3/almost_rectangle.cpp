#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(long long i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define um unordered_map 
#define foit(v) for (auto x: v) { cout << x; }
#define foum(umap) for (auto x : umap) {cout << x.first << " " << x.second << endl;}

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int i_1 = -1;
    int j_1 = -1;
    int i_2 = -1;
    int j_2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '*' && i_1 == -1 && j_1 == -1) {
                i_1 = i;
                j_1 = j;
            } else if (v[i][j] == '*') {
                i_2 = i;
                j_2 = j;
            }
        }
    }

    vector<vector<char>> new_v(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if ((i == i_1 && j == j_2) || (i == i_2 && j == j_1)) {
                new_v[i][j] = '*';
            } else {
                new_v[i][j] = v[i][j];
            }
        }
    }

    if (j_1 == j_2) {
    
        if (j_1 + 1 < n) {
            new_v[i_1][j_1 + 1] = '*';
            new_v[i_2][j_2 + 1] = '*';
        } else if (j_1 - 1 >= 0) {
            new_v[i_1][j_1 - 1] = '*';
            new_v[i_2][j_2 - 1] = '*';
        }
    } else if (i_1 == i_2) {
        if (i_1 + 1 < n) {
            new_v[i_1 + 1][j_1] = '*';
            new_v[i_2 + 1][j_2] = '*';
        } else if (i_1 - 1 >= 0) {
            new_v[i_1 - 1][j_1] = '*';
            new_v[i_2 - 1][j_2] = '*';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << new_v[i][j];
        }
        cout << '\n';
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}