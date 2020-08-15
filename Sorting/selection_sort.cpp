/*
https://www.youtube.com/watch?v=GUDLRan2DWM
*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    int minIndex;
    for(int i=0; i<n-1; i++) {
        minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    selectionSort(arr, n);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
