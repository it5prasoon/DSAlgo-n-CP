#include <bits/stdc++.h>
using namespace std;

float squareRoot(float n)
{
	float x = n;
	float y = 1;

	float e = 0.000001; 
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = n/x;
	}
	return x;
}

int findMaximumHeight(int N)
{
	int n = 1 + 8*N;
	int maxH = (-1 + squareRoot(n)) / 2;
	return maxH;
}

int main()
{
	int N = 12;
	cout << findMaximumHeight(N) << endl;
	return 0;
}
