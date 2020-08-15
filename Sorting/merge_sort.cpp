/*
https://www.youtube.com/watch?v=TzeBrDU-JaY
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int left[], int right[], int arr[], int n) {
    int mid = n/2;
    int i=0, j=0, k=0;
    while(i < mid && j < n-mid) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < mid) {
        arr[k++] = left[i++];
    }
    while(j < n-mid) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) {
    if(n < 2)
        return;
    int mid = n/2;
    int left[mid], right[n-mid];
    
    for(int i=0; i<mid; i++)
        left[i] = arr[i];
    for(int i=mid; i<n; i++)
        right[i-mid] = arr[i];
        
    mergeSort(left, mid);
    mergeSort(right, n-mid);
    
    merge(left, right, arr, n);
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr, n);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
