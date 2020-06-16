#include<bits/stdc++.h>
#define MAX 300
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int res[MAX];
int size;

// void initialize() {
//     size = 1;
//     res[0] = 1;
// }

// int digits(int num) {
//     int count = 0;
//     while(num != 0) {
//         count++;
//         num /= 10;
//     }
//     return count;
// }

void mul(int a) {
    int carry = 0;
    int p;
    for(int i=0; i<size; i++) {
        p = res[i] * a + carry;
        res[i] = p % 10;
        carry = p / 10;
    }
    // if(carry != 0) {
    //     int prev_size = size;
    //     size += digits(carry);
    //     for(int i=size-1; i>=prev_size; i--) {
    //         res[i] = carry%10;
    //         carry /= 10;
    //     }
    // }
    while(carry != 0) {
        res[size] = carry % 10;
        carry /= 10;
        size++;
    }
}

void fact(int n) {
    // initialize();
    size = 1;
    res[0] = 1;
    
    for(int i=2; i<=n; i++) {
        mul(i);
    }
}

int main() {
    int n;
    cin >> n;
    fact(n);
    for(int i=size-1; i>=0; i--) {
        cout << res[i];
    }
    return 0;
}