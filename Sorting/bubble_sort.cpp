/*
https://www.youtube.com/watch?v=Jdtq5uKz-w4
*/
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n-1-k; i++) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
    }
}

void bubbleSortImproved(int arr[], int n) {
    int flag;
    for(int k=0; k<n; k++) {
        flag = 0;
        for(int i=0; i<n-1-k; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSortImproved(arr, n);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
