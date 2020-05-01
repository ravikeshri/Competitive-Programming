/*
Time Complexity: O(Log Exp)
*/

#include<bits/stdc++.h>

using namespace std;

//recursive

int fast(int base, int exp){
	int result;
	if(exp == 0)  //base ^ 0 = 1(base condition)
		return 1;
	result = fast(base,exp/2); // base ^ exp/2
	result *= result; // (base ^ exp/2) ^ 2
	if(exp & 1) // checking for odd
		return result*base; // result for odd power
	return result; // result for even power

}

// iterative

int fast2(int base, int exp){
	int result = 1;
	while(exp > 0){
		if(exp & 1) // satisfied for the last loop i.e. when exp=1
					// and for odd exp
			result *= base;
	// now exp is always even except for the last loop i.e. when exp=1
		base *= base;
		exp /= 2;
	}
	return result;
}

int main(){
	int a, n;
	cin >> a >> n;
	cout << fast(a,n) << endl << fast2(a,n);
	return 0;
}
