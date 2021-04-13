/*
The dragon has a hit point of x initially. When its hit point goes to 0 or under 0, it will be defeated. In order to defeat the dragon, Kana can cast the two following types of spells.

Void Absorption
Assume that the dragon's current hit point is h, after casting this spell its hit point will become ⌊h2⌋+10. Here ⌊h2⌋ denotes h divided by two, rounded down.

Lightning Strike
This spell will decrease the dragon's hit point by 10. Assume that the dragon's current hit point is h, after casting this spell its hit point will be lowered to h−10.

Due to some reasons Kana can only cast no more than n Void Absorptions and m Lightning Strikes. She can cast the spells in any order and doesn't have to cast all the spells. Kana isn't good at math, so you are going to help her to find out whether it is possible to defeat the dragon.

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases.

The next t lines describe test cases. For each test case the only line contains three integers x, n, m (1≤x≤105, 0≤n,m≤30)  — the dragon's intitial hit point, the maximum number of Void Absorptions and Lightning Strikes Kana can cast respectively.

Output
If it is possible to defeat the dragon, print "YES" (without quotes). Otherwise, print "NO" (without quotes).

You can print each letter in any case (upper or lower).

input
7
100 3 4
189 3 4
64 2 3
63 2 3
30 27 7
10 9 1
69117 21 2

output
YES
NO
NO
YES
YES
YES
YES
Note
One possible casting sequence of the first test case is shown below:

Void Absorption ⌊1002⌋+10=60.
Lightning Strike 60−10=50.
Void Absorption ⌊502⌋+10=35.
Void Absorption ⌊352⌋+10=27.
Lightning Strike 27−10=17.
Lightning Strike 17−10=7.
Lightning Strike 7−10=−3.


*/


#include<bits/stdc++.h>

#define ll long long int
#define fo(i, n) for (long long i = 0; i < n; i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);cout<<fixed<<setprecision(16);
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(s) scanf("%s",&s)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define ps(s) printf("%s\n",s)

const int mod = 1000000007;
//====================================

using namespace std;



int32_t main()
{
	IOS;
    int t; si(t);
    while(t--){
        int x,n,m;
        si(x); si(n); si(m);
       
       bool ok = false;

       fo(i,n+1){
           int v=x;
           fo(j,i) v=v/2 +10;
           fo(j,m) v-=10;

           if(v<=0) ok=true;
       }
       cout<< (ok? "YES\n" : "NO\n");
    }
	return 0;
}