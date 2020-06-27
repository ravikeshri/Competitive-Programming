/*
Time Complexity: O(k^3.logN), k = size of the matrix
Q: Fibonacci Numbers, Output modulo 10^9 + 7
x = f0, y = f1, find fn.
*/

#include <bits/stdc++.h>

using namespace std;

// multiplying matrix a and b and storing the result in a

void mul(long a[2][2], long b[2][2]) {
    long temp[2][2];
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (k = 0; k < 2; k++)
                temp[i][j] += (a[i][k] % 1000000007 * b[k][j] % 1000000007) % 1000000007;
        }
    }
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            a[i][j] = temp[i][j];

}

//taking a^n and storing result in a

void power(long a[2][2], long n, long x, long y) {
    long mat[2][2] = {{1, 1},
                      {1, 0}};   // making a copy of original matrix so that we don't lost this matrix, (because we are overwriting the original matrix
    if (n == 0) {  // return identity matrix
        a[0][0] = 1;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 1;
        return;
    }
    power(a, n / 2, x, y);
    mul(a, a);  //squaring
    if (n & 1) //checking for odd
        mul(a, mat);
}

long f(long n, long x, long y) {
    long mat[2][2] = {{1, 1},
                      {1, 0}};
    if (n == 0)
        return x;
    if (n == 1)
        return y;
    power(mat, n - 1, x, y);
    return ((mat[0][0] % 1000000007 * y % 1000000007) % 1000000007 +
            (mat[0][1] % 1000000007 * x % 1000000007) % 1000000007) % 1000000007;

}

int main() {
    long t;
    cin >> t;
    while (t--) {
        long x, y, n; // f(0) = x , f(1) = y, we have to compute f(n)
        cin >> x >> y >> n;
        cout << f(n, x, y) << endl;
    }

    return 0;
}
