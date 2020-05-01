/*
Time Complexity: O(sqrt(n))
phi(n) = number of numbers (x) less than n such that gcd(n,x) = 1
*/

#include<iostream>
using namespace std;

int phi(int n) {
	int res = n; //initially consider every elements are prime to n
	for(int i=2; i*i<=n; i++) {
		if(n % i == 0) {

			// if n is divisible by i, remove all factors of i
			while(n % i == 0)
				n /= i;

			// subtract no of factors of i from res
			res -= res/i;
		}
	}
	// if a prime factor exists, remove its count from res
	if(n > 1) {
		res -= res/n;
	}
	return res;
}

int main() {
	cout << phi(12);
	return 0;
}
