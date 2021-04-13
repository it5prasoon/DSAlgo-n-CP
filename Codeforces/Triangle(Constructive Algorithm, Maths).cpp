/* You are given four positive integers a, b, c, d, such that a≤b≤c≤d.

Your task is to find three integers x, y, z, satisfying the following conditions:

a≤x≤b.
b≤y≤c.
c≤z≤d.
There exists a triangle with a positive non-zero area and the lengths of its three sides are x, y, and z.
Ichihime desires to get the cookie, but the problem seems too hard for her. Can you help her?

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases.

The next t lines describe test cases. Each test case is given as four space-separated integers a, b, c, d (1≤a≤b≤c≤d≤109).

Output
For each test case, print three integers x, y, z  — the integers you found satisfying the conditions given in the statement.

It is guaranteed that the answer always exists. If there are multiple answers, print any. 

Input
4
1 3 5 7
1 5 5 7
100000 200000 300000 400000
1 1 977539810 977539810

Output
3 4 5
5 5 5
182690 214748 300999
1 977539810 977539810
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


const int mod = 1000000007;
//====================================

using namespace std;



int32_t main()
{
	IOS;
    int t; si(t);
    while(t--){
        int a,b,c,d;
        si(a); si(b); si(c); si(d);
        cout<<b<<" "<<c<<" "<<c<<endl;

    }
	return 0;
}