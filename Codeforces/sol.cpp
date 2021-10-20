// C++ program to Count of n digit numbers
// whose sum of digits equals to given sum
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void findCount(int n, int sum) {
		
		int start = pow(10, n-1);
		int end = pow(10, n)-1;
	
		int count = 0;
		int i = start;
		
				while(i <= end) {
			
			int cur = 0;
			int temp = i;
			
			while( temp != 0) {
				cur += temp % 10;
				temp = temp / 10;
			}
			
			if(cur == sum) {			
				count++;			
				i += 9;		
			}else
				i++;
			
		}	
			cout << count;

	}
int main() {
    int n = 3;
    int sum = 5;	
    findCount(n,sum);
    
	
	return 0;
}
