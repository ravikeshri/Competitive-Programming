/*
https://www.youtube.com/watch?v=COk73cpQbFQ
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int pIndex = start;
	for(int i=start; i<end; i++) {
		if(arr[i] <= pivot) {
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	return pIndex;
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
    	int pIndex = partition(arr, start, end);
    	quickSort(arr, start, pIndex - 1);
    	quickSort(arr, pIndex + 1, end);
	}
}

int main() {
    int arr[] = {2, 5, 1, 6, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    return 0;
}
