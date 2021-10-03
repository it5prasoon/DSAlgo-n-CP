#include <bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (ll ll i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);

#define ld ll double
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

using namespace std;


ll min(ll a,ll b)
{
    return a>b?b:a;
}
int compare (const void * a, const void * b) {
   return ( *(ll*)a - *(ll*)b );
}

void solve(int T) {
    for(int i=0;i<T;i++)
	{
	    ll n;
	    scanf("%ld",&n);
	    ll arr[10000001];
	    ll counter=0;
	    for(ll i=0;i<n;i++)
	    {
	        ll m;
	        scanf("%ld",&m);
	        for(ll j=0;j<m;j++)
	        {
	            scanf("%ld",&arr[counter]);
	            counter++;
	        }
	    }
	    qsort(arr,counter,sizeof(ll),compare);
	    ll point=-1;
	    int p=1;
		ll l=0;
		int z=0;
		
        if(arr[0]<0)
        {
            for(int i=0;i<counter;i++)
            {       
	        	if(arr[i]>0&&p==1)
		        {
		            point=l;
		            p=0;
		        }
		        if(arr[i]==arr[i+1])
		        continue;
		        l++;
		       }
         }
		else
		{
			z=1;
		}
	    if(z)
	    printf("0\n");
	    else if(point==-1)
	    {
	    	if(arr[counter]>0)
	    	printf("%ld\n",l-1);
	    	else
	    	printf("0\n");
		}
		else
		{
		    ll k=min(point,l-point);
		    ll ans=k;
		    ans*=(l-k);
	        printf("%ld\n",ans);
		}
	}
}


int32_t main() {
	int T;
	scanf("%d",&T);
	solve(T);
    return 0;
}