#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define T vector<ll>
#define sync ios_base::sync_with_stdio(false); 

using namespace std; 
  
ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
        return gcd(b, a%b);
}  
// Extended Euclidean Algorithm  
ll gcdExtended(ll a, ll b, ll *x, ll *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1; // To store results of recursive call  
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  

vector<T > postfix(string s)
{
    
    ll bracket = 0;
    T number;
    ll num;
    num = 748683265;
    for(ll i = 0; i < 4; i++)number.push_back(num);
    vector<T > ans;
    T R, And, Xr;
    R.push_back(1);And.push_back(2);Xr.push_back(3);
    stack<char> buf;
    for(ll n  = 0 ; n < s.size(); n++)
    {
        if(s[n] == '#')
        {
            ans.push_back(number);
            continue;
        }
        if(s[n] == ')')
        {
            while(buf.top() != '(')
            {
                if(buf.top() == '|')
                {
                    ans.push_back(R);
                }
                else if(buf.top() == '&')
                {
                    ans.push_back(And);
                }
                else if(buf.top() == '^')
                {
                    ans.push_back(Xr);
                }
                buf.pop();
            }
            buf.pop();
        }
        else if(s[n] == '(' || buf.empty() || buf.top() == '(')
        {
            buf.push(s[n]);
        }
        else 
        {
            if(buf.top() == '|')
            {
                ans.push_back(R);
            }
            else if(buf.top() == '&')
            {
                ans.push_back(And);
            }
            else if(buf.top() == '^')
            {
                ans.push_back(Xr);
            }
            buf.pop();
            buf.push(s[n]);
        }
    }
    while(!buf.empty())
    {
        if(buf.top() == '|')
            ans.push_back(R);
        else if(buf.top() == '&')
            ans.push_back(And);
        else if(buf.top() == '^')
            ans.push_back(Xr);
        buf.pop();
    }
    return ans;
}

ll Add(ll a, ll  b)
{
   return (a+b)%MOD;
}

ll mul(ll a, ll b)
{
   return (a*b)%MOD;
}

T Orcalc(T a, T b)
{
    T ans(4);
    ll buf;
    ll term1;
    ans[0] = (a[0]* b[0]) %MOD;
    term1 = b[0];
    for(ll n = 1; n < 4; n++)
    {
        term1 = Add(term1, b[n]);
    }
    term1 = mul(term1, a[1]);

    ll term2 = a[0];
    term2 = Add(term2, a[2]);
    term2 = Add(term2, a[3]);
    term2 = mul(term2, b[1]);

    ll term3 = mul(a[2], b[3]);

    ll term4 = mul(a[3], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[1] = buf;

    term1 = mul(a[0], b[2]);
    term2 = mul(a[2], b[0]);
    term3 = mul(a[2], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[2] =buf;

    term1 = mul(a[0], b[3]);
    term2 = mul(a[3], b[0]);
    term3 = mul(a[3], b[3]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[3] = buf;

    return ans;
}


T Andcalc(T a, T b)
{
    T ans(4);
    ll buf;
    ll term1;
    ans[1] = mul(a[1], b[1]);

    term1 = b[0];
    for(ll n = 1; n < 4; n++)
    {
        term1 = Add(term1, b[n]);
    }
    term1 = mul(term1, a[0]);

    ll term2;
    term2 = a[1];
    term2 = Add(term2, a[2]);
    term2 = Add(term2, a[3]);
    term2 = mul(term2, b[0]);

    ll term3;
    term3 = mul(a[2], b[3]);

    ll term4;
    term4 = mul(a[3], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[0] = buf;

    term1 = mul(a[1], b[2]);
    term2 = mul(a[2], b[1]);
    term3 = mul(a[2], b[2]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[2] = buf;

    term1 = mul(a[1], b[3]);
    term2 = mul(a[3], b[1]);
    term3 = mul(a[3], b[3]);

    buf = term1;
    buf = Add(term1, term2);
    buf = Add(buf, term3);

    ans[3] = buf;

    return ans;
}

T Xorcalc(T a, T b)
{
    ll buf;
    ll term1, term2, term3, term4;
    T ans(4);
    
    term1 = mul(a[0], b[0]);
    term2 = mul(a[1], b[1]);
    term3 = mul(a[2], b[2]);
    term4 = mul(a[3], b[3]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[0] = buf;

    term1 = mul(a[0], b[1]);
    term2 = mul(a[1], b[0]);
    term3 = mul(a[2], b[3]);
    term4 = mul(a[3], b[2]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[1] = buf;


    term1 = mul(a[0], b[2]);
    term2 = mul(a[1], b[3]);
    term3 = mul(a[2], b[0]);
    term4 = mul(a[3], b[1]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);

    ans[2] = buf;

    term1 = mul(a[0], b[3]);
    term2 = mul(a[1], b[2]);
    term3 = mul(a[2], b[1]);
    term4 = mul(a[3], b[0]);
    buf = term1;
    buf = Add(buf, term2);
    buf = Add(buf, term3);
    buf = Add(buf, term4);
    
    ans[3] = buf;

    return ans;
}


ll CalcInv(ll a)
{
    ll x, y;
    ll gcd = gcdExtended(a, MOD, &x, &y);
    while(x < 0) x += MOD;
    return x%MOD;
}

// Driver Code 
int main()  
{  
    ll t1;
    cin>>t1;
    for(ll t = 0; t < t1; t++)
    {
        string s;
        cin>>s;
        ll num = 0;
        vector<T >  pfix = postfix(s);
        stack<T > st;
        T ele;
        for(ll n = 0; n < pfix.size(); n++)
        {
            ele = pfix[n];
            if(ele.size() == 4)
            {
                st.push(ele);
            }
            else if(ele.size() == 1)
            {
                T a, b, c;
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                if(ele[0] == 1)
                    c = Orcalc(a, b);
                if(ele[0] == 2)
                    c = Andcalc(a, b);
                if(ele[0] == 3)
                    c = Xorcalc(a, b);
                st.push(c);
            }
        }
        ele = st.top();
        T ans(4);
        for(ll i = 0; i < 4; i++)
        {
            ans[i] = ((ele[i]))%MOD;
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}  