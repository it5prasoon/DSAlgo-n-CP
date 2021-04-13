#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define pb push_back
#define mapr make_pair
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

double n,point[100005];

vector<pair<double,double> > line;
void linecreate()
{
    for(int i=2;i<=n;i++)
    {
        double dy=point[i]-point[i-1];
        double dx=1;
        double m=dy/dx;
        double c=point[i-1]-m*(i-1);
        line.pb(mapr(m,c));
    }
}
ll isintersect(double x1,double x2,double y)
{
    ll res=0;
    for(int i=1;i<x2;i++)
    {
        double m=line[i].fir;
        double c=line[i].sec;
        if(m!=0)
        {
           double x=(y-c)/m;
               if(x>=x1 && x<=x2 && x>=i && x<=i+1)
               if(((i)!=x2 || y!=point[i]) && ((i+1)!=x1 || y!=point[i+1]))
               {
                   res++;
               }
        }
        else
        {
            if(c==y)
                res++;
        }

    }
    return res;
}
int32_t main()
{
    sync;
    long t;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%lf",&n);
        ll q;
        scanf("%lld",&q);
        line.clear();
        line.pb(mapr(0,0));
        for(int i=1;i<=n;i++)
            scanf("%lf",&point[i]);
        linecreate();
        for(int i=0;i<q;i++)
        {
            double x1,x2,y;
            scanf("%lf %lf %lf",&x1,&x2,&y);
            printf("%lld\n",isintersect(x1,x2,y));
        }

    }

}