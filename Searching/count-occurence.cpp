/*
First and Last Occurence of a number in a sorted array

A = [2, 4, 4, 4, 4, 4, 7]

B = 4, first = 1, last = 5 (B found)
B = 6, first = -1, last = -1 (B not found)
*/
#include<bits/stdc++.h>
using namespace std;

int firstOcc(const vector<int> &A, int B) {
    
    int lo = 0;
    int hi = A.size()-1;
    int mid, res = -1;
    
    while(lo <= hi) {
        mid = lo + (hi - lo)/2;
        
        // if found
        if(A[mid] == B) {
            res = mid; // possible answer
            hi = mid - 1; // look left for first B
        } else if(A[mid] > B)
            hi = mid - 1;
        else
           lo = mid + 1; 
    }
    
    return res;
}

int lastOcc(const vector<int> &A, int B) {
    int lo = 0;
    int hi = A.size()-1;
    int mid, res = -1;
    while(lo <= hi) {
        mid = lo + (hi - lo)/2;
        if(A[mid] == B) {
            res = mid; // possible answer
            lo = mid + 1; // look right for last B
        } else if(A[mid] < B)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return res;
}

int main() {
    
    vector<int> A = {1, 2, 2, 2, 5};
    int B = 2; // search element
    
    cout << "First Occurence of B: " << firstOcc(A, B);
    cout << "\nLast Occurence of B: " << lastOcc(A, B);
}