// Fair election
// Fair Election

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

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vi a; vi b;

        for (int i=0; i<n; i++ ){
            int x; cin>>x;
            a.pb(x);
        }

        for (int i=0; i<m; i++) {
            int x; cin>>x; 
            b.pb(x);
        }

        sort(a.begin(), a.end()); sort(b.begin(), b.end(), greater<int>());
        
        int sum1=0, sum2=0, count=0;

        // for(int i=0; i<m; i++) {
        //     swap(a[i], b[m-i-1]);
        //     // cout << a[i] << b[m-i-1] << " ";
        //     sum1 = accumulate(a.begin(),a.end(),0);
        //     // cout << sum1<<" ";
        //     sum2 = accumulate(b.begin(),b.end(),0);
        //     // cout << sum2<<" ";
        //     count++;
        //     if (sum1 > sum2) {
        //         break;
        //     }
        //     else {
        //         continue;
        //     }
        // }  

        int i=0,j=0;
        sum1 = accumulate(a.begin(), a.end(), 0);
        sum2 = accumulate(b.begin(), b.end(), 0);
        while(sum1<=sum2){
             sum1-=a[i]; sum1+=b[j];
             sum2-=b[j]; sum2+=a[i];
             count++;
             i++,j++;
             if(i==n || j==m)
                {
                    break;
                }
        }
        if(sum1>sum2)
            cout<<count<<endl;
        else 
            cout<<-1<<endl;

    }
    return 0;
}

// john jackson and jack jhonson final stage