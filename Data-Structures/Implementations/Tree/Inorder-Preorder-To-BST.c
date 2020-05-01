/* 	A binary tree from Inorder and Preorder traversals. */

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

struct node *buildTree(int in[], int pre[], int inStart, int inEnd) {
	static int p = 0; //start from 0 and increases upto n-1
	if(inStart > inEnd)
		return NULL;
	struct node *root = createNode(pre[p]);
	p++;
	if(inStart == inEnd)
		return root;
	int i; // i refers to root index in Inorder
	for(i=inStart; i<=inEnd; i++) {
		if(in[i] == root->data)
			break;
	}
	// Preorder = Root -> Left -> Right
	root->left = buildTree(in, pre, inStart, i-1);
	root->right = buildTree(in, pre, i+1, inEnd);
	return root;
}


/*postrder*/

void postOrder(struct node *root) {
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}

/*main function*/

int main() {
	int i, n;
	printf("Enter size: ");
	scanf("%d",&n);
	int in[n];
	int pre[n];

	printf("Enter inorder: ");
	for(i=0; i<n; i++)
		scanf("%d",&in[i]);

	printf("Enter preorder: ");
	for(i=0; i<n; i++)
		scanf("%d",&pre[i]);

	struct node *root = buildTree(in, pre, 0, n-1);
	printf("\nPostorder of constructed tree is:\n");
	postOrder(root);
	return 0;
}
