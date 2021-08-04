#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


class Solution
{
    public:
    
    vector<string> sv;
    
    void printParenthesis(int pos, int n, int open, int close) {
        static char str[1000];
        if (close == n) {
            sv.push_back(str);
            return;
        }
        else {
            if (open > close){
                str[pos] = ')';
                printParenthesis(pos + 1, n, open, close + 1);
            }
         
            if (open < n){
                str[pos] = '(';
                printParenthesis(pos + 1, n, open + 1, close);
            }
            
        }
    }
    
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> p;
      
        printParenthesis(0,n,0,0);
        p = sv;
        // p.push_back(printParenthesis(0,n,0,0));
        
        return p;
    }
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
