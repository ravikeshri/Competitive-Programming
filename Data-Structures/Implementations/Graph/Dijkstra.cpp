/*
Single Source Shortest Path Algorithm
*/

#include <bits/stdc++.h>

using namespace std;

void dijkstra(int n, vector<vector<int> > G, int s) {
    //selected will store the record of nodes selected with min dist
    vector<bool> selected(n, false);
    //dist to store the distance of each node from s(source) node
    //initially infinity
    vector<int> dist(n, INT_MAX);
	//vector<int> parent (n); can be made to store the path

    //dist of S from S is always 0
    dist[s] = 0;

    //we don't look for the min distance on the last iteration
    //we just select the last node
    //so running loop for last iteration is not neccessary
    for(int k=0; k<n-1; k++) {

		//to find the element with min dist
        int minDist = INT_MAX, minIndex;
        for(int i=0; i<n; i++) {
            if(!selected[i] && minDist > dist[i]) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        //this index will now be explored
        int u = minIndex;
        //selecting this node
        selected[u] = true;


		//if a node is not selected and it is a neighbour of u
		// then d(v) = min( d(u) + w(u,v) , d(v) )
        for(int v=0; v<n; v++) {
            if(!selected[v] && G[u][v] != 0 && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v]; //parent[v] = u;
        }
    }

    printf("\nDist of each node from %d is:\n",s);
    for(int i=0; i<n; i++) {
    	printf("%d",dist[i]);
    }
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

  printf("Enter source vertex: ");
  int s;
  cin >> s;

	prims(n, G, s);

	return 0;
}
