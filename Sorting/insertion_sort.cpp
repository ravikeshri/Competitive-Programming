/*
https://www.youtube.com/watch?v=i-SKeOcBwko
*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int value, hole;
    for(int i=1; i<n; i++) {
        value = arr[i];
        hole = i;
        while(hole > 0 && arr[hole-1] > value) {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr, n);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
