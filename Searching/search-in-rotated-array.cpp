/*
Approach 1: 

Find the index of smallest element say key
Search for the element in the two sorted parts 
binarySearch(0, key-1) || binarySearch(key, n-1)

Approach 2:
(Direct binary search)
Code below
*/

#include <bits/stdc++.h>
using namespace std;

int search(const vector<int> &A, int B) {
    int lo = 0, hi = A.size() - 1;
    int mid;
    
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        
        if(A[mid] == B) 
            return mid;
            
        // if left part is sorted
        else if(A[lo] <= A[mid]) {
            
            // if B lies in left discard right
            if(A[lo] <= B && B <= A[mid]) hi = mid-1;
            // else discard left
            else lo = mid+1;
        } 
        
        // if right part is sorted
        else { 
            
            // if B lies in right discard left
            if(A[mid] <= B && B <= A[hi]) lo = mid+1;
            // else discard right
            else hi = mid-1;
        }
    }
    // if B doesn't exist
    return -1;
}

int main()
{
    vector<int> A = {4, 5, 6, 7, 0, 1, 2};
    int B = 6; // search element
    
    cout << "Index of B is: " << search(A, B);
    return 0;
}