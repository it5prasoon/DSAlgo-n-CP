#include <iostream> 
using namespace std; 

void isKthBitSet(int n, int k) 
{ 
	if (n & (1 << (k - 1))) 
		cout << "SET"; 
	else
		cout << "NOT SET"; 
} 

int main() 
{ 
	int n = 39, k = 5; 
	isKthBitSet(n, k); 
	return 0; 
} 
