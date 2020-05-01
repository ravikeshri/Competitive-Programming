/*
Implementation of Stack using Linked List
*/

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

void *display(struct stackNode *stack) {
	struct stackNode *p = stack;
	while(p != NULL) {
		printf("%d\t",p->data);
		p = p->next;
	}
}

int main() {
	struct stackNode *stack = NULL;
	printf("%d",peek(stack));
	stack = push(stack, 2);
	stack = push(stack, 6);
	stack = push(stack, 1);
	stack = push(stack, 4);
	stack = push(stack, 5);
	stack = push(stack, 7);
	stack = pop(stack);
	printf("%d",peek(stack));
	stack = pop(stack);

	display(stack);
	return 0;
}
