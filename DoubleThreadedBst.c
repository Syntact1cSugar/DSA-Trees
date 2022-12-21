#include<stdio.h>
#include<stdlib.h>

struct DTNode
{
	struct DTNode* left;
	int LT;
	int info;
	int RT;
	struct DTNode* right;
};
void Insert(int info,struct DTNode* Head)
{
	struct DTNode* newNode = (struct DTNode*)malloc(sizeof(struct DTNode));
	(*newNode).LT = (*newNode).RT = 1;
	(*newNode).info = info;
	(*newNode).right = (*newNode).left = NULL;
	if((*Head).left == NULL)
	{
		(*Head).left = newNode;
		(*newNode).right = (*newNode).left = Head;
		return;//Root Node Created and Linked
	}
	struct DTNode* current = (*Head).left;
	while(current)
	{
		if(info <= (*current).info)
		{
			if((*current).LT == 1)
			{
				(*newNode).left = (*current).left;
				(*newNode).right = current;
				(*current).left = newNode;
				(*current).LT = 0;
				current = NULL;
			}	
			else current = (*current).left;
		}
		else if(info > (*current).info)
		{
			if((*current).RT == 1)
			{
				(*newNode).left = current;
				(*newNode).right = (*current).right;
				(*current).right = newNode;
				(*current).RT = 0;
				current = NULL;
			}
			else current = (*current).right;
		}
	}	
	return;
}
void Inorder(struct DTNode* Head)
{
	if((*Head).left == NULL)
	{
		printf("No nodes in the tree!\n");
		return;
	}
	struct DTNode* current = (*Head).left;
	while(current)
	{
		while((*current).LT == 0)
			current = (*current).left;
		printf("%d\t",(*current).info);
		while((*current).RT == 1)
		{
			current = (*current).right;
			if(current == Head)return;//Break from loop condition
			printf("%d\t",(*current).info);
		}
		current = (*current).right;
	}
	return;
}
void Preorder(struct DTNode* Head)
{
	if((*Head).left == NULL)
	{
		printf("No nodes in the tree!\n");
		return;
	}
	struct DTNode* current = (*Head).left;
	while(current != Head)
	{
		while((*current).LT == 0)
		{
			printf("%d\t",(*current).info);
			current = (*current).left;
		}
		printf("%d\t",(*current).info);
		while((*current).RT == 1)
		{
			current = (*current).right;
		}
		current = (*current).right;
	}
	printf("\n");
	return;

}
int main()
{
	//Creation of Header Node
	struct DTNode* Head = (struct DTNode*)malloc(sizeof(struct DTNode));
	//Initialising the state of the Header Node
	(*Head).right = Head;
	(*Head).left = NULL;
	(*Head).info = 69;
	(*Head).RT = (*Head).LT = 0;
	Insert(4,Head);
	Insert(3,Head);
	Insert(5,Head);
	Insert(6,Head);
	Inorder(Head);
	printf("\n");
	Preorder(Head);
	return 0;
}
