/*  Breadth first search.*/

#include<stdio.h>
#include<stdlib.h>

struct queueNode {
	int data;
	struct queueNode *next;
};

struct queueNode *enq(struct queueNode *q, int data) {
	if(q == NULL) {
		q = (struct queueNode *)malloc(sizeof(struct queueNode));
		q->data = data;
		q->next = NULL;
		return q;
	}
	struct queueNode *tmp = (struct queueNode *)malloc(sizeof(struct queueNode));
	tmp->data = data;
	struct queueNode *p = q;
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->next = NULL;
	return q;
}

struct queueNode *deq(struct queueNode *q) {
	if(q == NULL)
		return q;
	struct queueNode *tmp = q;
	q = q->next;
	free(tmp);
	return q;
}

int front(struct queueNode *q) {
	if(q == NULL)
		return -1;
	return q->data;
}

void bfs(int n, int arr[][n], int s) {
	int i;
	int visited[n];
	visited[0] = 0;
	struct queueNode *q = NULL;
	q = enq(q, s);
	visited[s] = 1;

	int first;
	while(q != NULL) {
		first = front(q);
		q = deq(q);
		printf(" %d", first+1);

		for(i=0; i<n; i++) {
			if(arr[first][i] == 1 && visited[i] != 1) {
				q = enq(q, i);
				visited[i] = 1;
			}

		}
	}
}

int main() {
	int n;
	printf("Enter no. of nodes: ");
	scanf("%d", &n);
	int arr[n][n];
	printf("Enter the adjacency matrix ( 0-1 matrix) of size %d:\n",n);
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	int s;
	printf("Enter start vertex: ");
	scanf("%d", &s);

	printf("BFS traversal is:\n");
	bfs(n, arr, s-1);

	return 0;
}
