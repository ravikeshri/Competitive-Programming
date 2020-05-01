/*
Hackerrank Question "Connected Cells" Solution
Similar to "No. of Islands Problem"
Concept: DFS
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int j, vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == 0)
        return 0;

    matrix[i][j] = 0;

    return 1 + dfs(i, j-1, matrix) + dfs(i+1, j-1, matrix) + dfs(i+1, j, matrix) + dfs(i+1, j+1, matrix) + dfs(i, j+1, matrix) + dfs(i-1, j+1, matrix) + dfs(i-1, j, matrix) + dfs(i-1, j-1, matrix);

}

int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int i, j;
    int size = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(matrix[i][j] == 1) {
                size = max(size, dfs(i, j, matrix));
            }
        }
    }
    return size;
}
