/*
Time Complexity: O(sqrt(n))
*/

#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if(n <= 1) // 0 and 1 is not prime
		return false;
	if(n <= 3) // 2 and 3 is prime
		return true;
	if(n % 2 == 0 || n % 3 == 0) //multiple of 2 and 3 not prime
		return false;

	// Any number can be expressed as 6k + j, j=0,1,2,3,4,5
	// j=0,2,4, are multiple of 2
	// j=3, are multiple of 3
	// j=5, 6k+5 can be written as 6k-1
	// 6k+1 and 6k-1 are primes

	// any number having prime factor can't be prime
	//checking if a number has a factor of the form 6k +- 1

	for(int i = 5; i <= sqrt(n); i = i + 6) { // i = 6k-1
		if(n % i == 0 || n % (i+2) == 0) // i+2 = 6k+1
			return false;
	}
	return true;
}

// A brut-force approach is given below

bool isPrimeSimple(int n) {
	if(n <= 1)
		return false;
	for(int i=2; i<= sqrt(n); i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n, i, j;
	cin >> n;
	isPrime(n) ? cout << "Prime" : cout << "Non-Prime";
	cout << endl;
	isPrimeSimple(n) ? cout << "Prime" : cout << "Non-Prime";
	return 0;
}
