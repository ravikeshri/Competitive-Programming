/* Depth first search.*/

#include<stdio.h>
#include<stdlib.h>

struct stackNode {
	int data;
	struct stackNode *next;
};

struct stackNode *push(struct stackNode *stack, int data) {
	if(stack == NULL) {
		stack = (struct stackNode *)malloc(sizeof(struct stackNode));
		stack->data = data;
		stack->next = NULL;
		return stack;
	}
	struct stackNode *tmp = (struct stackNode *)malloc(sizeof(struct stackNode));
	tmp->data = data;
	struct stackNode *p = stack;
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->next = NULL;
	return stack;
}

struct stackNode *pop(struct stackNode *stack) {
	if(stack == NULL)
		return stack;
	if(stack->next == NULL) {
		struct stackNode *tmp = stack;
		stack = NULL;
		free(tmp);
		return stack;
	}
	struct stackNode *last, *p = stack;
	while(p->next != NULL) {
		last = p;
		p = p->next;
	}
	last->next = NULL;
	free(p);
	return stack;
}

int peek(struct stackNode *stack) {
	if(stack == NULL)
		return -1;
	struct stackNode *p = stack;
	while(p->next != NULL)
		p = p->next;
	return p->data;
}

void dfs(int n, int arr[][n], int s) {
	int i;
	int visited[n];
	visited[0] = 0;
	struct stackNode *stack = NULL;
	stack = push(stack, s);
	visited[s] = 1;

	int top;
	while(stack != NULL) {
		top = peek(stack);
		stack = pop(stack);
		printf(" %d", top+1);

		for(i=0; i<n; i++) {
			if(arr[top][i] == 1 && visited[i] != 1) {
				stack = push(stack, i);
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

	printf("DFS traversal is:\n");
	dfs(n, arr, s-1);

	return 0;
}
