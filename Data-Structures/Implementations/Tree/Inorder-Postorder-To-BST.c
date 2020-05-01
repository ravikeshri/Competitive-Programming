/* 	A binary tree from Inorder and Postorder traversals. */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNode(int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Tree building function

struct node *buildTree(int in[], int post[], int inStart, int inEnd, int *p) {
	//can't use "static int p = n-1;" as variable assignment to static int is illegal,
	if(inStart > inEnd)
		return NULL;
	struct node *root = createNode(post[*p]);
	(*p)--;
	if(inStart == inEnd)
		return root;
	int i; // i refers to root index in Inorder
	for(i=inStart; i<=inEnd; i++) {
		if(in[i] == root->data)
			break;
	}

	// Postorder = Left <- Right <- Root
	root->right = buildTree(in, post, i+1, inEnd, p);
	root->left = buildTree(in, post, inStart, i-1, p);
	return root;
}


/*preorder*/

void preOrder(struct node *root) {
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

/*main function*/

int main() {
	int i, n;
	printf("Enter size: ");
	scanf("%d",&n);
	int in[n];
	int post[n];

	printf("Enter inorder: ");
	for(i=0; i<n; i++)
		scanf("%d",&in[i]);

	printf("Enter postorder: ");
	for(i=0; i<n; i++)
		scanf("%d",&post[i]);

	int p = n-1; // start from n-1 and decrease upto 0
	struct node *root = buildTree(in, post, 0, n-1, &p);
	printf("\nPreorder of constructed tree is:\n");
	preOrder(root);
	return 0;
}
