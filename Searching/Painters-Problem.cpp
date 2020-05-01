/*
Time Complexity: O(n * log(sum(arr[])))
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

// this function will check how may painters
// will be required if max is the limit for each
// if no. of painters exceeds the given no. x
// return false
// otherwise true (for <= x)
bool optimalPainters(ll max, ll arr[], ll n, ll x) {
	// initially no of painters = 1
    ll painters = 1;
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        sum += arr[i];
        if(sum > max) {
            painters++;
            sum = arr[i];
        }
        if(painters > x)
            return false;
    }
    return true;
}

ll binarySearch(ll start, ll end, ll x, ll arr[], ll n) {
    ll mid;
    while(start < end) {
        mid = (start + end)/2;

        // if no of painters > x,
        // choosing smaller mid value will increase the
        // no of painters, so increase the mid value to
        // obtain painters = x

        if(!optimalPainters(mid, arr, n, x)) {
        	// mid is not an optimal solution
        	// so choose mid+1 for further calculation
            start = mid + 1;
        }
        else {
        	// if painters = x,
        	// this is one possible solution
        	// try to reduce this
        	// (include mid as this is a possible solution)
            end = mid;
        }
    }
    return start;
}

int main() {
    ll n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll maxEle = *max_element(a, a+n);
    ll x, timePerUnit;
    cin >> x >> timePerUnit;

    // solution will always lie between
    // max element and sum of all elements
    // because there should be atleast one painter
    // who can cover the largest segment
    // so, lower limit is maxEle
    // In worst case, one painter will cover the entire board
    // so, upper limit is sum of all elements

    ll units = binarySearch(maxEle, sum, x, a, n);
    cout << units * timePerUnit;
    return 0;
}
