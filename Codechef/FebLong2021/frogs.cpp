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

int getIn(vi v, int K) {
        auto it = find(v.begin(), v.end(), K);

        if (it != v.end() ) {
            int index = it - v.begin();
            return index;
        }
        else return -1;
}

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vi w,l;
        int x; fo(i,n) {cin>>x; w.pb(x);}
        int y; fo(i,n) {cin>>y; l.pb(y);}


        vi p,b;
        fo (i,n) {
            p.pb(i);
        }
        b = w;
        // fo(i,n) {cout<<p[i] <<" "<< b[i];}
        sort(b.begin(), b.end());

        int count=0;

        // fo(i,n) {cout<<p[i] <<" "<< b[i];}
        
        for (ll i=1; i<n; i++) {
           int in = getIn(w, b[i]);
           int pos = p[getIn(w, b[i-1])];
           int tmp = in;

            while (tmp<=pos) {
                tmp += l[in];
                p[in] = tmp;
                count++;
            }
        }

        cout << count << endl;


    }
    return 0;
}