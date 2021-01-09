/*
Question: 
https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


Algorith:
        
    we have to add k to some elements and subtract k from remaining
    now split the array into two halves,
    arr[i1]...arr[ip] and arr[ip+1]...arr[iq]
    suppose these two halves are sorted.
    we will add k to 1st half and subtract k from the 2nd half
    min of 1st half = arr[i1]+k and max = arr[ip]+k
    min of 2nd half = arr[ip+1]-k and max = arr[iq]-k
    overall min = min(arr[i1]+k, arr[ip+1]-k)
    overall max = max(arr[ip]+k, arr[iq]-k)
    res = min of all such (max-min)
    
    we will sort the array in ascending order
    and partion the array into [0...i] and [i...n-1]
    Increase all elements before, and decrease all elements after
    arr[i] (including it) by k.
    
    find max and min element according to above mentioned algorithm
    in each step and variable res will store min of all such (max-min)
    partitions are:
    []        [0...n-1]
    [0...0]   [1...n-1]
    [0...1]   [2...n-1]
    [0...2]   [3...n-1]
    ...
    ...
    [0...n-2] [n-1...n-1]
    [0...n-1] []
    
    
    also we will find min and max only when 'arr[i] >= k' because:
    if arr[i] < k then we can't decrease k from [arr[i]...arr[n-1]]
    because arr[i] will be negative, so only choice is to increase [arr[i]...arr[n-1]],
    after which all elements will be increased since arr[0]...arr[i-1] is already increased
    and that will not help us as the difference remains same
    also we cannot decrease [arr[0]...arr[i-1]] because arr[i] < k and so all elements
    upto arr[i-1] < k
        
Solution:
*/

#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        
    sort(arr, arr+n);
    int max_element, min_element;
    
    // base case when one of the halfs is empty
    int res = arr[n-1]-arr[0];
    
    for(int i=1; i<n; i++) {
        
        if(arr[i] >= k) {
            
            // partitions are:
            // [arr[0]...arr[i-1]]
            // [arr[i]...arr[n-1]]
            
            min_element = min(arr[0]+k, arr[i]-k);
            max_element = max(arr[i-1]+k, arr[n-1]-k);
            
            res = min(res, max_element - min_element);
        }
    }
    
    return res;
}

int main() {
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2; 

    cout << getMinDiff(arr, n, k); 
    
    return 0; 
}
