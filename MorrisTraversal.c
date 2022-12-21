#include<stdio.h>
#include<stdlib.h>
//Morris Traversal for Binary Search Tree
struct bstNode
{
	struct bstNode* left;
	int info;
	struct bstNode* right;
};
//Morris Traversal(Inorder)
void MorrisTraversal(struct bstNode* root)
{
	if(!root)return;
	while(root != NULL)
	{
		if((*root).left == NULL)
		{
			printf("%d\t",root->info);
			root = (*root).right;
		}
		else//Left Subtree exists 
		{
			struct bstNode* RightMostChild/**in left subtree**/= root->left;
			while(RightMostChild->right != NULL && RightMostChild->right != root)
				RightMostChild = RightMostChild->right;
			//Right Pointer could be NULL or pointing to Inorder Successor
			if(RightMostChild->right == NULL)//Threading
			{
				(*RightMostChild).right = root;
				root = (*root).left;
			}
			else if(RightMostChild->right == root)//Dethreading
			{
				(*RightMostChild).right = NULL;
				printf("%d\t",(*root).info);
				root = (*root).right;
			}
		}
	}

	return;
}
void Insert(int info,struct bstNode** ptrToRoot)
{
	struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
	(*newNode).info = info;
	(*newNode).right = (*newNode).left = NULL;
	struct bstNode* root = *ptrToRoot;
	if(!root)
	{
		*ptrToRoot = newNode;
		return;
	}
	while(root)
	{
		if(info <= (*root).info)
		{
			if((*root).left == NULL)
			{
				(*root).left = newNode;
				root = NULL;
			}
			else root = (*root).left;
		}
		else if(info > (*root).info)
		{
			if((*root).right == NULL)
			{
				(*root).right = newNode;
				root = NULL;
			}
			else root = (*root).right;
		}
	}
	return;
}
int main()
{
	struct bstNode* root = NULL;
	Insert(90,&root);
	Insert(150,&root);
	Insert(80,&root);
	Insert(99,&root);
	Insert(69,&root);
	MorrisTraversal(root);
	return 0;
}
