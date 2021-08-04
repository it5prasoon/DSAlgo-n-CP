#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);
#define gc getchar_unlocked
#define ld long double
#define PI (ld)3.1415926535897932384626
#define pb push_back
#define vi vector<int>
#define viii vector<tuple<int,int,int>>
#define F first
#define S second
#define pt(a) for(auto it:a)cout<<*it<<" ";cout<<endl; 
                                        


const int mod = 1000000007;
//====================================

void swapall(ll *a, ll i1, ll i2, ll i3)
{
	ll temp = a[i3];
	a[i3] = a[i2];
	a[i2] = a[i1];
	a[i1] = temp;
}


int main()
{
	IOS

	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll p[n],b[n];
		for(ll i=0;i<n;i++)
		{
			cin>>p[i];
			b[i] = p[i];	
		}
		sort(b,b+n);

		unordered_map<ll,ll>idx;


		for(ll i=0; i<n;i++)
			idx[b[i]] = i;

		ll ans = 0;

		vector<pair<ll,pair<ll,ll>>> steps;
		ll prevf=-1,prevs=-1,i1,i2,i3;

		for(ll i=0; i<n; )
		{
			if(p[i]==b[i] || prevs==i) 
			{
				i++;
				continue;
			}
			i1 = i;
			i2 = idx[p[i1]];
			i3 = idx[p[i2]];
			if(i3==i1 && prevf==-1)
			{
				prevf = i1;
				prevs = i2;
				i++;
				continue;
			}
			else if(i3==i1)
			{
				i1 = prevf;
				i2 = prevs;
				i3 = i;
				prevf=-1;
				prevs=-1;
			}

			swapall(p,i1,i2,i3);
			ans++;
			steps.push_back({i1+1,{i2+1,i3+1}});
			if(p[i1]==b[i1])
				i++;

			if(ans>k)
			{
				ans = -1;
				break;
			}
		}

		if(prevf!=-1) ans = -1;

		if(ans<=k && ans!=-1)
		{
			cout<<ans<<"\n";
			for(auto &x: steps)
				cout<<x.F<<" "<<x.S.F<<" "<<x.S.S<<"\n";
		}
		else
			cout<<"-1\n";
	}

	return 0;
}