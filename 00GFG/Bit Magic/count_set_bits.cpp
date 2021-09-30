#include <bits/stdc++.h> 
using namespace std; 

unsigned int countSetBits(int n) 
{ 
   unsigned int count = 0; 
   while (n) { 
      n &= (n - 1); 
      count++; 
   } 
   return count; 
} 

unsigned int getFirstSetBit(int n)
{
   return log2(n & -n) + 1;
}

int main() 
{ 
	int i = 9; 
	cout << countSetBits(i) << endl;
   cout << getFirstSetBit(i) << endl; 
	return 0; 
} 
