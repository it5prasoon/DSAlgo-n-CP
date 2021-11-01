#include <iostream>
using namespace std;

bool isPow2(int n)
{
    if (n<0) return false;
    if (n==1) return true;
    if (n==0) return false;
        
    return ((n&(n-1))==0);
}
    
int main() {
	
	int n = 16;
	
	printf("%s", isPow2(n)? "true": "false");
}