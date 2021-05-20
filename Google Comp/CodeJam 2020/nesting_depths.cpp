#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution(vector<int> &v, int start, int end, vector<vector<string> > &paren)
{
	if(start>end) 
        return;
	if(v[start] == 0)
		{
			solution(v, start+1, end, paren);
		}
	else if(v[end] == 0)
	{
		solution(v, start, end-1, paren);
	}
	else
	{
		vector<int> zeros;
		for(int i=start; i<=end; i++)
		{
			v[i]--;
			if(v[i] == 0)
				zeros.push_back(i);
		}
		paren[start].push_back("open");
		paren[end+1].push_back("close");
		if(zeros.size() == 0)
			{
				solution(v, start, end, paren);
			}
		else{
			int newstart = start;
			int i=0;
			for(i=0; i<zeros.size(); i++)
			{
				int bpoint = zeros[i];
				solution(v, newstart, bpoint-1, paren);
				newstart = bpoint+1;
			}
			solution(v, newstart, end, paren);
		}
	}

}

int main()
{
	int T;
	cin>>T;
	for(int c=1; c<=T; c++)
	{
		string s;
		cin>>s;
		vector<int> v;
		for(int i=0; i<s.length(); i++)
		{
			v.push_back((int)s[i] - 48);
		}
		vector<vector<string> > paren(s.length()+1);
		vector<int> zeros;
		for(int i=1; i<s.length()-1; i++)
		{
			if(s[i] == '0') zeros.push_back(i);
		}
		if(zeros.size() == 0)
			solution(v, 0, v.size()-1, paren);
		else
		{
			int newstart = 0;
			for(int i=0; i<zeros.size(); i++)
			{
				int bpoint = zeros[i];
				solution(v, newstart, bpoint-1, paren);
				newstart = bpoint+1;
			}
			solution(v, newstart, s.length()-1, paren);
		}
		cout<<"Case #"<<c<<": ";
		for(int i=0; i<s.length(); i++)
		{
			vector<string> br = paren[i];
			for(int j=0; j<paren[i].size(); j++)
			{
				if(paren[i][j] == "open") cout<<"(";
				else if(paren[i][j] == "close") cout<<")";
			}
			cout<<s[i];
		}
		for(int i=0; i<paren[paren.size()-1].size(); i++)
		{
			if(paren[paren.size()-1][i] == "open") cout<<"(";
				else if(paren[paren.size()-1][i] == "close") cout<<")";
		}
		cout<<endl;
		
	}
	}