/* Adjacency List Implementation
	a. Create an edge between two nodes.
	b. Remove an edge between two nodes.
	c. Degree of a particular node.
	d. Create a new node
	e. Remove an existing node.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int vertex;
	struct node *next;
};

struct Graph {
	int n; // no of vertices
	struct node **adjList; // pointer to a list of pointers
};

struct Graph *createGraph(int noOfVertex) {
	struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
	G->n = noOfVertex;
	G->adjList = (struct node **)malloc(G->n * sizeof(struct node *));

	int i;
	for(i=0; i<G->n; i++) {
		G->adjList[i] = (struct node *)malloc(sizeof(struct node));
		G->adjList[i]->vertex = i;
		G->adjList[i]->next = NULL;
	}
	return G;
}

void addEdge(struct Graph *G, int u, int v) {
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->vertex = v;
	tmp->next = NULL;
	struct node *p = G->adjList[u];
	while(p->next != NULL) {
		if(p->next->vertex == v) {
			printf("Edge already exists!!!");
			return;
		}
		p = p->next;
	}
	p->next = tmp;

	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->vertex = u;
	tmp->next = NULL;
	p = G->adjList[v];
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;

	return;
}

void removeEdge(struct Graph *G, int u, int v) {
	struct node *pre, *p, *tmp;
	pre = NULL;
	p = G->adjList[u];
	int flag = 0;
	while(p->next != NULL) {
		pre = p;
		p = p->next;
		if(p->vertex == v) {
			pre->next = p->next;
			free(p);
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		return; //edge doesn't exist

	pre = NULL;
	p = G->adjList[v];
	while(p->next != NULL) {
		pre = p;
		p = p->next;
		if(p->vertex == u) {
			pre->next = p->next;
			free(p);
			break;
		}
	}
}

int deg(struct Graph *G, int u) {
	struct node *p = G->adjList[u];
	int count = 0;
	while(p->next != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

void addVertex(struct Graph *G) {
	G->n++;
	G->adjList = (struct node **)realloc(G->adjList, G->n * sizeof(struct node *));

	G->adjList[G->n - 1] = (struct node *)malloc(sizeof(struct node));
	G->adjList[G->n - 1]->vertex = G->n - 1;
	G->adjList[G->n - 1]->next = NULL;
}

void removeVertex(struct Graph *G, int u) {
	if(u >= G->n) {
		printf("Vertex doesn't exist!!");
		return;
	}
	int i;
	for(i=0; i<G->n; i++)
		removeEdge(G, u, i);
	G->adjList[u]->next = NULL;
	G->adjList[u]->vertex = -1;
}

void printGraph(struct Graph *G) {
	if(G == NULL) {
		printf("Graph is empty!!");
		return;
	}
	int i;
	struct node *p;
	for(i=0; i<G->n; i++) {
		p = G->adjList[i];
		while(p != NULL) {
			if(p->vertex == -1)
				continue;
			printf(" %d -->",p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

int main() {
	int n, e, i;
	int u, v;
	struct Graph *G = NULL;
	while(1) {
		printf("\n\n1. Create graph\n2. Create an edge between two nodes\n3. Remove an edge between two nodes\n4. Degree of a particular node\n5. Create a new node\n6. Remove an existing node\n7. Print Graph in list form\nAny other to 'EXIT'\n");
		printf("\nNote: Graph starts with vertex 0\nEnter Choice: ");
		int c;
		scanf("%d",&c);
		switch(c) {
			case 1:
				printf("Enter no of Vertex: ");
				scanf("%d",&n);
				G = createGraph(n);
				break;
			case 2:
				if(G == NULL) {
					printf("Create Graph First!!!");
					break;
				}
				printf("\nEnter u and v: ");
				scanf("%d%d",&u,&v);
				addEdge(G, u, v);
				break;
			case 3:
				if(G == NULL) {
					printf("Graph is empty!!!");
					break;
				}
				printf("\nEnter u and v: ");
				scanf("%d%d",&u,&v);
				removeEdge(G, u, v);
				break;
			case 4:
				if(G == NULL) {
					printf("Graph is empty!!!");
					break;
				}
				printf("Enter vertex: ");
				scanf("%d",&v);
				printf("Degree of vertex %d is: %d ", u, deg(G, u));
				break;
			case 5:
				if(G == NULL) {
					G = createGraph(1);
					break;
				}
				addVertex(G);
				break;
			case 6:
				if(G == NULL) {
					printf("Graph is empty!!!");
					break;
				}
				printf("Enter vertex to be removed: ");
				scanf("%d",&u);
				removeVertex(G, u);
				break;
			case 7:
				printGraph(G);
				break;
			default:
				exit(0);
		}
	}

	return 0;
}
