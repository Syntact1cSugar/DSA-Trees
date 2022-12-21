#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	struct TreeNode *left,*right;
	int data;
};
void inorder(struct TreeNode* root)
{
	if(root == NULL)return;
	inorder((*root).left);
	printf("%d\t",root->data);
	inorder((*root).right);
	return;
}
struct TreeNode* insert(struct TreeNode* root,int dataIn)
{
	if(!root)
	{
		root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		(*root).data = dataIn;
	}
	else if(dataIn <= (*root).data)
		(*root).left = insert((*root).left,dataIn);
	else if(dataIn > (*root).data)
		(*root).right = insert((*root).right,dataIn);
	return root;
}
int Ancestors(struct TreeNode* root,int key)
{
	if(root == NULL)return 0;
	if((*root).data == key)
	{
		printf("Ancestors of %d are :\t",key);
		return 1;
	}
	int flag;
	if(key < (*root).data)
		flag = Ancestors((*root).left,key);
	else if(key > (*root).data)
		flag = Ancestors((*root).right,key);
	if(flag)
		printf("%d\t",(*root).data);
	return flag;
int main()
{
	struct TreeNode* root = NULL;
	return 0;
}
