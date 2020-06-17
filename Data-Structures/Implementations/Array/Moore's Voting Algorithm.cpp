// Check if an element occurs more than n/2 in array
// time complexity O(n), space complexity O(1)

#include<bits/stdc++.h>
#define MAX 40005
#define ll long long

using namespace std;

int moore(vector<int> &A) {
    int n = A.size();
    
    // step:1 (find the possible candidate)
    // if an element occurs more than n/2,
    // than cancelling its count with other 
    // elements will give atleast count = 1
    // we will store that number
    int count=1, num=A[0];
    for(int i=1; i<n; i++) {
        if(num == A[i]) {
            count++;
        } else if(count == 0) {
            num = A[i];
            count++;
        } else {
            count--;
        }
    }
    
    // step:2 (check if it is the required number)
    count = 0;
    for(int i=0; i<n; i++) {
        if(num == A[i]) count++;
    }
    
    if(count > n/2) 
        return num;
        
    // if not, return -1
    return -1;
}

int main() {
    vector<int> A = {1, 3, 1, 1, 2};
    cout << moore(A);
    return 0;
}