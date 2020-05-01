/*
Time Complexity: O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

// iterative

int binarySearch(vector <int> arr, int start, int end, int ele){
    int mid;
    while(start <= end){ // loop ends when start > end
        mid = (start + end)/2; //calculate mid each time
        if(arr[mid] == ele) // element at exact mid position
            return mid;
        else if(ele < arr[mid]) //elemnt at left part of the array
            end = mid - 1;  //shift left
        else // elemnt at the right part of the array
            start = mid + 1;       //shift right
    }
    return -1; //when element not found
}

// recursive

int binarySearch2(vector <int> arr, int start, int end, int ele){
    int mid;
    if(start <= end){
        mid = (start + end)/2;
        if(arr[mid] == ele)
            return mid;
        else if(ele < arr[mid])
            return binarySearch2(arr, 0, mid-1, ele);
        return binarySearch2(arr, mid+1, end, ele);
    }
    return -1;
}


int main(){
	vector <int> arr = {2, 3, 6, 8, 9, 16, 18, 22};
	int ele = 8; //search element
	int n = arr.size();
	int result1 = binarySearch(arr, 0, n-1, ele);
	int result2 = binarySearch2(arr, 0, n-1, ele);
	if(result1 == -1 || result2 == -1)
		cout << "Element doesn't exist" << endl;
	else {
		cout << "Position is: " << result1 << endl;
		cout << "Position is: " << result2 << endl;
	}
	return 0;
}
