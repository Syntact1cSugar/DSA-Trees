#include<stdio.h>
#include<stdlib.h>

struct bstNode
{
	struct bstNode* r;
	int info;
	struct bstNode* l;
};
void Insert(int data,struct bstNode** ptrToRoot)
{
	struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
	newNode->info = data;
	(*newNode).r = (*newNode).l = NULL;
	if(*ptrToRoot == NULL)
	{
		*ptrToRoot = newNode;
		return;
	}
	struct bstNode* auxPtr = *ptrToRoot;
	while(auxPtr)
	{
		if(data < auxPtr->info)
		{
			if((*auxPtr).l == NULL)
			{
				(*auxPtr).l = newNode;
				auxPtr = NULL;
			}
			else auxPtr = (*auxPtr).l;
		}
		else if(data > auxPtr->info)
		{
			if((*auxPtr).r == NULL)
			{
				(*auxPtr).r = newNode;
				auxPtr = NULL;
			}
			else auxPtr = (*auxPtr).r;
		}
	}
	return;
}
void Inorder(struct bstNode* root)
{
	if(!root)return;//Base case condition
	Inorder((*root).l);
	printf("%d\t",(*root).info);
	Inorder((*root).r);
}
struct bstNode* CreateExternalNode()
{
	struct bstNode* externalNode = (struct bstNode*)malloc(sizeof(struct bstNode));
	externalNode->info = -1;
	externalNode->r = externalNode->l = NULL;
	return externalNode;
}
struct bstNode* ExtendTree(struct bstNode* root)
{
	if(root == NULL)return CreateExternalNode();
	root->l = ExtendTree(root->l);
	root->r = ExtendTree(root->r);
	return root;
}
int main()
{
	struct bstNode* root = NULL;//Stores the refernce of the root node of the tree
	Insert(5,&root);
	Insert(4,&root);
	Insert(10,&root);
	Inorder(root);
	printf("\n");
	ExtendTree(root);
	Inorder(root);
	return 0;
}
