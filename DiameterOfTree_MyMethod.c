
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


int height(struct TreeNode* root)
{
	if(root == NULL)return -1;
	int lh = height(root->left);
	int rh = height(root->right);
	return (lh > rh)? lh+1 : rh+1;
}
int findDiameter(struct TreeNode* root,int diameter)
{
	if(root == NULL)return diameter;
	int newDiameter = height(root->left)+height(root->right)+3;
	if(newDiameter > diameter)
		diameter = newDiameter;
	int ld = findDiameter(root->left,diameter);
	int rd = findDiameter(root->right,diameter);
	return (ld > rd)? ld : rd;
}
int main()
{
	return 0;
}

