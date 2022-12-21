#include<stdio.h>
#include<stdlib.h>

struct RTNode
{
	int data;
	int RT;
	struct RTNode* right;
	struct RTNode* left;
};
int Insert(int data,struct RTNode* Head)
{
	struct RTNode* newP = (struct RTNode*)malloc(sizeof(struct RTNode));
	newP->data = data;
	newP->RT = 1;
	newP->left = NULL;
	if(!(*Head).left)
	{
		Head->left = newP;
		newP->right = Head;
		return 0;
	}
	struct RTNode* current = Head->left;
	while(current)
	{
		if(data <= current->data)
		{
			if(!current->left)
			{
				current->left = newP;
				newP->right = current;
				current = NULL;//To terminate the loop
			}
			else current = current->left;
		}
		else if(data > current->data)
		{
			if(current->RT == 1)
			{
				newP->right = current->right;
				current->RT = 0;
				current->right = newP;
				current = NULL;//To terminate the loop
			}
			else current = current->right;
		}
	}
	return 1;
}
int Inorder(struct RTNode* Head)
{
	if(!Head->left)return 0;
	struct RTNode* current = Head->left;
	while(current != Head)
	{
		while(current->left)
			current = current->left;
		printf("%d\t",current->data);
		while(current->RT != 0 && current->right != Head)
		{
			current = current->right;
			printf("%d\t",current->data);
		}
		current = current->right;
	}
	return 0;
}
/**
struct RTNode* LeftMostChild(struct RTNode* root)
{
	if(!root)return NULL;
	while(root->left)
		root = root->left;
	return root;
}
void InorderL(struct RTNode* Head)
{
	if(!Head->left)return;
	struct RTNode* current = LeftMostChild(Head->left);
	while(current!=Head)
	{
		printf("%d\t",current->data);
		if(current->RT == 1)
			current = current->right;
		else current = LeftMostChild(current->right);
	}
	return;
}**/
void Preorder(struct RTNode* Head)
{
	if((*Head).left == NULL)return;
	struct RTNode* current = Head->left;
	while(current!=Head)
	{
		printf("%d\t",current->data);
		while(current->left != NULL)
		{
			current = current->left;
			printf("%d\t",current->data);
		}
		while(current->RT == 1)
			current = current->right;
		current = current->right;
	}
}
int main()
{
	//creation of Head(also called dummy)node
	struct RTNode* Head = (struct RTNode*)malloc(sizeof(struct RTNode));
	(*Head).data = -1;
	(*Head).RT = 0;
	(*Head).left = NULL;
	(*Head).right = Head;
	Insert(40,Head);
	Insert(30,Head);
	Insert(70,Head);
	Insert(20,Head);
	Insert(34,Head);
	Insert(50,Head);
	Insert(100,Head);
	Inorder(Head);
	return 0;
}
