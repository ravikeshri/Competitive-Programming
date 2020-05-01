/*
Time Complexity: O(Log Exp)
*/

#include<bits/stdc++.h>

using namespace std;

//recursive

int modular(int base, int exp, int mod){
	int result;
	base %= mod;
	if(exp == 0)  //base ^ 0 = 1(base condition)
		return 1;
	result = fast(base,exp/2); // base ^ exp/2
	result = (result*result) % mod; // (base ^ exp/2) ^ 2
	if(exp & 1) // checking for odd
		return (result*base) % mod; // result for odd power
	return result % mod; // result for even power

}

// iterative

int modular2(int base, int exp, int mod){
	int result = 1;
	base %= mod;
	while(exp > 0){
		if(exp & 1) // satisfied for the last loop i.e. when exp=1
					// and for odd exp
			result = (result*base) % mod;
	// now exp is always even except for the last loop i.e. when exp=1
		base = (base*base) % mod;
		exp /= 2;
	}
	return result;
}

int main(){
	int a, n, mod;
	cin >> a >> n >> mod;
	cout << modular(a,n,mod) << endl << modular2(a,n,mod);
	return 0;
}
