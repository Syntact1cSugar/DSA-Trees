#include<stdio.h>
#include<stdlib.h>

struct bstNode
{
	int data;
	struct bstNode* left;
	struct bstNode* right;
};
struct bstNode* createNode(int data)
{
	struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
	(*newNode).left = (*newNode).right = NULL;
	(*newNode).data = data;
	return newNode;
}
struct bstNode* Insert(int data,struct bstNode* root)
{
	if(!root)
	{
		return createNode(data);
	}
	struct bstNode* temp = root;
	struct bstNode* prev = NULL;
	while(temp)
	{
		if(data <= root->data)
		{
			prev = temp;
			temp = temp->left;
		}
		if(data > root->data)
		{
			prev = temp;
			temp = temp->right;
		}
	}	
	if(data <= prev->data)
		prev->left = createNode(data);
	else if(data > prev->data)
		prev->right = createNode(data);
	return root;

}
void inorder(struct bstNode* root)
{
	if(!root)return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
int findMin(struct bstNode *root)
{
	if(!root)return -1;
	while(root->left != NULL)
		root = root->left;
	return root->data;
}
int findMax(struct bstNode* root)
{
	if(!root)return -1;
	while(root->right != NULL)
		root = root->right;
	return root->data;
}
int searchItem(int item,struct bstNode* root)
{
	if(!root)return 0;
	while(root)
	{
		if(root->data == item)
			return 1;
		else if(item < root->data)
			root = root->left;
		else if(item > root->data)
			root = root->right;
	}
	return 0;
}

int main()
{
	struct bstNode* root = NULL;
	root = Insert(5,root);
	root = Insert(5,root);
	root = Insert(10,root);
	root = Insert(2,root);
	printf("Inorder Traversal\n");
	inorder(root);
	printf("\nMaximum element in bst : %d\nMinimum element in bst : %d\n",findMax(root),findMin(root));
	printf("%d",searchItem(1,root));
	printf("\n%d\n",searchItem(69,root));
	return 0;
}
