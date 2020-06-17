// Check if an element occurs more than n/3 times in array
/*
    Based on Moore's Voting Algorithm
*/
// time complexity O(n), space complexity O(1)

#include<bits/stdc++.h>
#define MAX 40005
#define ll long long

using namespace std;

int moore(vector<int> &A) {
    int n = A.size();
    
    // step:1 (find the possible candidates)
    int c1=0, c2=0, num1=MAX, num2=MAX; // num1 & num2 = MAX or -1 or any number outside range
    for(int i=0; i<n; i++) {
        if(num1 == A[i]) {
            c1++;
        } else if(num2 == A[i]) {
            c2++;
        } else if(c1 == 0) {
            num1 = A[i];
            c1++;
        } else if(c2 == 0) {
            num2 = A[i];
            c2++;
        } else {
            c1--;
            c2--;
        }
    }
    
    // step:2 (check if any of it is the required number)
    c1 = 0;
    c2 = 0;
    for(int i=0; i<n; i++) {
        if(num1 == A[i]) c1++;
        else if(num2 == A[i]) c2++;
    }
    
    if(c1 > n/3) return num1;
    if(c2 > n/3) return num2;
        
    // if not, return -1
    return -1;
}

int main() {
    vector<int> A = {1, 3, 1, 1, 2};
    cout << moore(A);
    return 0;
}