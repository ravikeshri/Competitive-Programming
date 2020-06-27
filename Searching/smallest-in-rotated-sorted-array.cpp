/*
Find the smallest element in rotated sorted array
*/

#include <bits/stdc++.h>
using namespace std;

int search(const vector<int> &A) {
    int lo = 0, n = A.size(), hi = n-1;
    int mid, prev, next;
    
    while(lo <= hi) {
        
        // if selected part is already sorted, return lo
        if(A[lo] <= A[hi])
            return lo; 
        mid = lo + (hi-lo)/2;
        
        // find prev and next element of mid
        // { consider the edge cases
        // edge case: (1) prev when mid is 0, (2) next when mid is n-1
        // take modulo A.size() }
        next = (mid+1)%n;
        prev = (mid-1+n)%n;
        
        // if smallest, prev and next will be larger
        if((A[mid] <= A[next]) && (A[mid] <= A[prev])) {
            return mid;
        }
        
        // if left part is sorted, go right
        else if(A[lo] <= A[mid])
            lo = mid + 1;
            
        // if right part is sorted, go left
        else if(A[mid] <= A[hi])
            hi = mid - 1;
    }
    return 0;
}

int main()
{
    vector<int> A = {4, 5, 6, 7, 0, 1, 2};

    cout << "Index of smallest elemet is: " << search(A);
    return 0;
}