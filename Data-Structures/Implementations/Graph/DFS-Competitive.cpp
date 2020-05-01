/*
Adjacency List representaion of Graph
for competitive programming
(DFS - Recursive)
*/

#include <bits/stdc++.h>

using namespace std;

void dfsUtil(int s, vector<bool>& visited, vector<vector<int> > adj) {
    visited[s] = true;
    cout << s << " ";
    for(auto x: adj[s]) {
        if(!visited[x])
            dfsUtil(x, visited, adj);
    }
}

void dfs(int n, int s, vector<vector<int> > adj) {
    vector<bool> visited (n, false);
    dfsUtil(s, visited, adj);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin >> s;

    dfs(n, s, adj);

    return 0;
}
