/*
	 Implementation of Binary Search Tree (BST).
		a. Insert a node into the BST.
		b. Delete a node from the BST.
		c. Display the preorder traversal of the BST.
		d. Display the inorder traversal of the BST.
		e. Display the postorder traversal of the BST.
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

/*Insert Node*/

struct node *createNode(struct node *root, int data) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insertNode(struct node *root, int data) {
	if(root == NULL)
		root = createNode(root, data);
	else {
		if(data < root->data)
			root->left = insertNode(root->left, data);
		else
			root->right = insertNode(root->right, data);
	}
	return root;
}

/*Insert Node ends here*/

/*Delete Node*/

struct node *inorderSucc(struct node *root) {
	struct node *temp = root;
	while(temp && temp->left != NULL)
		temp = temp->left;
	return temp;
}

struct node *deleteNode(struct node *root, int data) {
	if(root == NULL)
		return root;
	if(data < root->data)
		root->left = deleteNode(root->left, data);
	else if(data > root->data)
		root->right = deleteNode(root->right, data);
	else {
		struct node *temp;
		if(root->left == NULL) {
			temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL) {
			temp = root->left;
			free(root);
			return temp;
		}
		temp = inorderSucc(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

/*Delete Node ends here*/

/*preorder*/

void preOrder(struct node *root) {
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

/*inorder*/

void inOrder(struct node *root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

/*postorder*/

void postOrder(struct node *root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

/*main function*/

int main() {
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	int data;
	while(1) {
		printf("\n\n 1.Insert a node into the BST \n 2. Delete a node from the BST \n 3. Display the preorder traversal of the BST\n 4. Display the inorder traversal of the BST\n 5. Display the postorder traversal of the BST\n Any other to 'Exit'");
		printf("\n\nEnter choice: ");
		int c;
		scanf("%d",&c);
		switch(c) {
			case 1:
				printf("\nEnter data to insert: ");
				scanf("%d",&data);
				root = insertNode(root, data);
				break;
			case 2:
				printf("\nEnter data to delete: ");
				scanf("%d",&data);
				root = deleteNode(root, data);
				break;
			case 3:
				preOrder(root);
				break;
			case 4:
				inOrder(root);
				break;
			case 5:
				postOrder(root);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
