/*
Time Complexity: O(n)
Q: The Maximum Subarray Sum
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, i;
    cin >> n;
    ll arr[n];
    for(i=0; i<n; i++)
        cin >> arr[i];
    ll finalMax = INT_MIN; //-infinity so that negative answers should be considered
    ll currMax = 0; // 0 works fine here
    for(i=0; i<n; i++) {
        //if finalMax and currMax is initialized with arr[0], begin loop with i = 1
        currMax = max( arr[i], arr[i] + currMax); // check whether it is benefitial to carry the previous sum or not
        if(currMax > finalMax)
            finalMax = currMax;
    }
    cout << finalMax ;
    return 0;
}
