#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define replaceall(i, a, b) for(ll i = a; i < b; i++)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}


int main() {
    sync;
	ll t;
	scanf("%lld",&t);
	while(t--) {
		ll n, q;
		scanf("%lld %lld",&n,&q);
		vl a(n);
		pt points[n];
		replaceall(i, 0, n) {
			scanf("%lld",&a[i]);
			points[i] = pt(i+1, a[i]);
		}
		replaceall(i, 0, q) {
			ll x1, x2, y;
			scanf("%lld %lld %lld",&x1,&x2,&y);
			ll count = 0;
			pt a(x1, y), b(x2, y);
			replaceall(j, 1, x2) {
				if(check_inter(a, b, points[j-1], points[j])) {
					count++;
					if(b.x == points[j-1].x && b.y == points[j-1].y)
						count--;
					if(a.x == points[j].x && a.y == points[j].y)
						count--;
				}
			}
			printf("%lld\n",count);
		}
	}
	return 0;
}