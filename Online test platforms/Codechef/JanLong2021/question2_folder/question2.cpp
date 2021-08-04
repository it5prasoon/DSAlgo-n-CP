// Watching CPL

#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define f(i,n) for (long long i = 0; i <= n; i++)
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
#define input(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define us unordered_set<int> 

using namespace std;

int32_t main(){

  #ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
  #endif 
    int t; cin>>t;
    while(t--){
      ll n, k; us v1;

      cin>>n; cin>>k;
      ll h[n];

      input(h, n);
      sort(h, h + n);
      v1.insert(h[n-1]);
      int sum = h[n-1];
      int z = -1;
      for (int i = n-2; i>=0; i--) {
        us v2;
        sum += h[i];
        us :: iterator itv;
        itv = v1.begin();
        while(itv != v1.end()) {
            int p = *itv;

            v2.insert(p);
            v2.insert(h[i]);
            v2.insert(p+h[i]);
            if (p + h[i] >= k && sum - p - h[i] >= k) {
                z = n - i;
                break;
            }
            if (h[i] >= k && sum - h[i] >= k) {
                z = n - i;
                break;
            }
            itv++;
        }
        if (z != -1) {
          break;
        }
        v1 = v2;
      }
      cout<<z<<endl;     

      

    }
    return 0;
}