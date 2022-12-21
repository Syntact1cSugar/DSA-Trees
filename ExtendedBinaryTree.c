#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	struct TreeNode* right;
	int data;
	struct TreeNode* left;
};
struct TreeNode* newNode(int data)
{
	struct TreeNode* newN = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	(*newN).data = data;
	(*newN).left = (*newN).right = NULL;
	return newN;
}
struct TreeNode* Extend(struct TreeNode* root)
{
	if(root == NULL)//Base case
		return newNode(-1);
	root->left = Extend(root->left);
	root->right = Extend(root->right);
	return root;
}
void Inorder(struct TreeNode* root)
{
	if(!root)return;
	Inorder(root->left);
	printf("%d\t",root->data);
	Inorder(root->right);
	return;
}
int main()
{
	struct TreeNode* root = newNode(1);
	(*root).left = newNode(2);
	(*root).right = newNode(3);
	(*root).left->left = newNode(5);
	Inorder(root);
	printf("\n");
	Extend(root);
	Inorder(root);
	return 0;
}
