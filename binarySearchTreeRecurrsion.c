#include<stdio.h>
#include<stdlib.h>

struct bstNode
{
	int data;
	struct bstNode* right;
	struct bstNode* left;
};
struct bstNode* Insert(int data,struct bstNode* root)
{
	if(!root)
	{
		root = (struct bstNode*)malloc(sizeof(struct bstNode));
		root->left = root->right = NULL;
		root->data = data;
	}
	else if(data <= root->data)
	{
		root->left = Insert(data,root->left);
	}
	else if(data > root->data)
	{
		root->right = Insert(data,root->right);
	}
	return root;
}
void inorder(struct bstNode* root)
{
	if(!root)return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
int findMax(struct bstNode* root)
{
	if((*root).right == NULL)
		return root->data;
	return findMax(root->right);
}
int findMin(struct bstNode* root)
{
	if(root->left == NULL)
		return root->data;
	return findMin(root->left);
}
int searchItem(int item,struct bstNode* root)
{
	if(!root)return 0;
	if(root->data == item)
		return 1;
	return searchItem(item,root->left);
	return searchItem(item,root->right);
}
int searchOptimum(int item,struct bstNode* root)
{
	if(!root)return 0;
	if(root->data == item)return 1;
	if(item <= root->data)
		return searchOptimum(item,root->left);
	if(item > root->data)
		return searchOptimum(item,root->right);
}
int main()
{
	struct bstNode* root = NULL;
	root = Insert(5,root);
	root = Insert(2,root);
	root = Insert(9,root);
	root = Insert(1,root);
	root = Insert(3,root);
	printf("Inorder Traversal :\n");
	inorder(root);
	printf("\nMaximum Element in bst : %d\nMinimum Element in bst : %d\n",findMax(root),findMin(root));
	printf("%d",searchOptimum(10,root));
	printf("\n%d",searchOptimum(0,root));

	return 0;
}
