/*
https://www.programiz.com/dsa/heap-sort
*/

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int root) {
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
        
    if(root != largest) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n) {
    for(int i=n/2 - 1; i>=0; i--) {
        heapify(arr, n, i);
    }
    
    for(int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    heapSort(arr, n);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
