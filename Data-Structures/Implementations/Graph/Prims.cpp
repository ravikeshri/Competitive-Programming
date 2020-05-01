/*
Minimum Spanning Tree using Prim’s Algorithm
*/

#include <bits/stdc++.h>

using namespace std;

void prims(int n, vector<vector<int> > G) {
	//selected will store the record of nodes selected
    vector<bool> selected(n, false);
    //dist to store the distance of each node from its parent node
    vector<int> dist(n, INT_MAX);

    //parent will store the parent node of each node (to remember the path)
    vector<int> parent(n);

	//source doesn't matter in case of Prims
	//we can start from any node
	//here let S(source) = 0
    dist[0] = 0;
    //no parent of source
    parent[0] = -1;

	//we don't look for the min distance on the last iteration
    //we just select the last node
    //so running loop for last iteration is not neccessary
    int k, v;
    for(k = 0; k < n-1; k++) {

    	//to find the element with min dist
        int min = INT_MAX, minIndex;
        for(v = 0; v < n; v++) {
            if(!selected[v] && min > dist[v]) {
                min = dist[v];
                minIndex = v;
            }
        }
        //this index will now be explored
        int u = minIndex;
        //selecting this node
        selected[u] = true;


		//if a node is not selected and it is a neighbour of u
		// then d(v) = min( w(u,v) , d(v) )
        for(v = 0; v < n; v++) {
            if(!selected[v] && G[u][v] != -1 && G[u][v] < dist[v]) {
                dist[v] = G[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nPath is:\n");
    for(int i=0; i<n; i++) {
    	printf("%d <--> %d , weight = %d \n",parent[i],i,G[i][parent[i]]);
    }
    // sum of dist[] is the total cost of MST
}

int main() {
  int n, m, i, j, u, v, w;
	printf("Enter no. of vertices: ");
	cin >> n;
	vector<vector<int> > G(n, vector<int> (n, 0));

	printf("Enter no of edges: ");
	cin >> m;
	printf("Enter source, destination and weight of->\n");
	for(i=0; i<m; i++) {
		printf("Edge %d: ",i+1);
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}

	prims(n, G);

	return 0;
}
