#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

#define MAX 100005
#define ll long long

using namespace std;

int diameter[MAX];
bool visited[MAX];

int node; // farthest node from source
int max_height; // max height

void resetBFS() {
    memset(visited, false, sizeof(visited));
    memset(diameter, 0, sizeof(diameter));
}

int bfs(int s, vector<vector<int> > &adj) {
    resetBFS();
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        int n = adj[u].size();
        for(int i=0; i<n; i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                visited[v] = true;
                diameter[v] = diameter[u] + 1;
                q.push(v);
            }
        }
    }
    // returning node(index) with max diameter
    return max_element(diameter, diameter + adj.size()) - diameter;
}

int diameterBFS(vector<vector<int> > &adj) {
    // farthest node from 1
    int node1 = bfs(1, adj);
    // farthest node from that node
    int node2 = bfs(node1, adj);
    return diameter[node2];
}

void resetDFS() {
	max_height = INT_MIN;
	memset(visited, false, sizeof(visited));
}

void dfs(int s, vector<vector<int> > &adj, int height) {
	visited[s] = true;
	height++;
	int n = (int)adj[s].size();
	for(int i=0; i<n; i++) {
		int v = adj[s][i];
		if(!visited[v]) {
			if(height >= max_height) {
				max_height = height;
				// save the node value whenever max_height updated
				node = v;
			}
			dfs(v, adj, height);
		}
	}
}

int diameterDFS(vector<vector<int> > &adj) {
    // farthest node from 1
    resetDFS();
	dfs(1, adj, 0);
	// farthest node from that node
	resetDFS();
	dfs(node, adj, 0);
	
    return max_height;
}

int main() {
	int n;
	cin >> n;
	int a, b;
	vector<vector<int> > adj(n+5);
	// graph/tree input
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// diameter using bfs
	cout << diameterBFS(adj) << " ";
	// diameter using dfs
	cout << diameterDFS(adj);
	return 0;
}
