/*
Time Complexity: O(n * log(log(n)))
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;

	// Sieve of Eratosthenes

	//Making an array isPrime,
	//whose indices are the numbers to be checked
	//At first consider all are primes
	vector<bool> isPrime(n + 1, true);

	// 0 and 1 are not prime, so assign false
	isPrime[0] = false;
	isPrime[1] = false;

	for(i = 2; i <= sqrt(n); i++){ // for i >= 2
		if(isPrime[i]){ // if i is prime
			for(j = 2; i*j <= n; j++) //mark all multiples of i as non-prime
				isPrime[i*j] = false;

			// Use this Approach for understanding purpose
			// A faster approach is given below (recommended)

			//for(j = i * i; j <= n; j = j + i)
			//	isPrime[j] = false;
		}
	}

	//End of Sieve of Eratosthenes

	for(int i=2; i<=n; i++) {
		if(isPrime[i])
			cout << i << endl;
	}
	return 0;
}
