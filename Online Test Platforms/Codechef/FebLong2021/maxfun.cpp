#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld long double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

using namespace std;


long long absl(long long a, long long b, long long c)
{
    long long res = abs(a-b) + abs(b-c) + abs(c-a);
    return res;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
		ll n; cin >> n;
		vi a;
		int c;
		fo(i,n) {
			cin>>c;
			a.pb(c);
		}
		sort(a.begin(), a.end());

		ll sum = 0;
		fo(i,n) {
			sum = max(absl(a[0], a[1], a[n-1]), sum);
		}

		cout << sum << endl;	



    }
    return 0;
}