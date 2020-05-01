/*
Implementation of Queue using Linked List
*/

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

void *display(struct queueNode *q) {
	struct queueNode *p = q;
	while(p != NULL) {
		printf("%d\t",p->data);
		p = p->next;
	}
}

int main() {
	struct queueNode *q = NULL;
	printf("%d",front(q));
	q = enq(q, 2);
	q = enq(q, 6);
	q = enq(q, 1);
	q = enq(q, 4);
	q = enq(q, 5);
	q = enq(q, 7);
	q = deq(q);
	printf("%d",front(q));
	q = deq(q);

	display(q);

	return 0;
}
