#include<stdio.h>
#include<stdlib.h>

struct bstNode
{
	struct bstNode* left;
	int info;
	struct bstNode* right;
};
struct StackNode
{
	struct bstNode* TNodeAddress;
	struct StackNode* next;
}
*top = NULL;
int isEmpty()
{
	return (!top)? 1 : 0;
}
void Push(struct bstNode* AddressIn)
{
	struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	newNode->next = top;
	top = newNode;
	newNode->TNodeAddress = AddressIn;
}
struct bstNode* Pop()
{
	if(isEmpty())return NULL;
	struct StackNode* deletePtr = top;
	struct bstNode* AddressOut = top->TNodeAddress;
	top = top->next;
	free(deletePtr);
	return AddressOut;
}
struct bstNode* Insert(int infoIn,struct bstNode* root)
{
	if(root == NULL)
	{
		struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
		(*newNode).left = (*newNode).right = NULL;
		(*newNode).info = infoIn;
		root = newNode;
	}
	else if(infoIn <= (*root).info)
		root->left = Insert(infoIn,root->left);
	else if(infoIn > (*root).info)
		root->right = Insert(infoIn,root->right);
	return root;
}
void InorderStack(struct bstNode* root)
{
	if(!root)return;
	while(root != NULL)
	{
		Push(root);
		while(root->left != NULL)
		{
			root = root->left;
			Push(root);
		}
		root = Pop();
		printf("\t%d",root->info);
		root = root->right;
		while(root == NULL && !isEmpty())
		{
			root = Pop();
			printf("\t%d",root->info);
			root = root->right;
		}
	}
}
int main()
{
	struct bstNode* root = NULL;
	int i;
	for(i = 50;i<=100;i=i+10)
		root = Insert(i,root);
	for(i = 40;i>=0;i=i-10)
		root = Insert(i,root);
	InorderStack(root);
	return 0;
}
