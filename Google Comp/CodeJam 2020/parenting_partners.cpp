#include<bits/stdc++.h>
#define sync std::ios_base::sync_with_stdio(false);
#define ll long long int
#define pb(a) push_back(a)

using namespace std;

int main()
{
    sync cin.tie(0);
	int t;     
    cin >> t;
    for (ll k = 0; k < t; ++k){
       int n;
       cin >> n;    
       vector<int> s;          
       vector<int> s1;             
       multimap<int,int> m;  

       for (ll i = 0; i < n; ++i){
           int a,b;      
           cin >> a >> b; 
           s.pb(a);       
           s1.pb(a);
           m.insert(pair<int,int>(a,b));
       }  
       int tmp = 1;    
       int endc = 0;   
       int endj = 0;    
       string pk = "";     
       
       sort(s.begin(),s.end());     
       
       for (ll i = 0; i < n; ++i){
           if(s[i]>=endj){
               pk+="J";
               endj = m.find(s[i])->second;
               m.erase(m.find(s[i]));
           }
           else if(s[i]>=endc){
               pk+="C";
               endc = m.find(s[i])->second;
               m.erase(m.find(s[i]));
           }
           else{                 
               tmp = 0;
               break;
           }
       }
       
       if(tmp == 0){
           cout<<"Case #"<<k+1<<": IMPOSSIBLE"<<endl;
       }
       else{
           string res="";
           vector<int> :: iterator it;
           for(it=s1.begin();it!=s1.end();++it){
               int p = distance(s.begin(),find(s.begin(),s.end(),*it));
               s[p]=-1;
               res+=pk[p];
           }
           cout<<"Case #"<<k+1<<": "<<res<<" "<<endl; 
       }
    }

    return 0;
}