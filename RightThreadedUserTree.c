#include<stdio.h>
#include<stdlib.h>
struct RightThreadedNode
{
	int entry;
	struct RightThreadedNode* l;
	struct RightThreadedNode* r;
	int RightThread;
};
void inorder(struct RightThreadedNode* dummy)
{
	if(dummy->l == NULL)return;
	struct RightThreadedNode* auxPtr = dummy->l;
	while(1)
	{
		while(auxPtr->l)
			auxPtr = auxPtr->l;
		printf("%d\t",auxPtr->entry);
		while(auxPtr->RightThread == 1)
		{
			auxPtr = auxPtr->r;
			if(auxPtr == dummy)return;
			printf("%d\t",auxPtr->entry);
		}
		auxPtr = auxPtr->r;
	}
	return;
}
int isLChild(int entry)
{
	int ch;
	printf("\nLeft Child of %d? : ",entry);
	scanf("%d",&ch);
	return (ch==1)? 1 : 0;
}
int isRChild(int entry)
{
	int ch;
	printf("\nRight Child of %d? : ",entry);
	scanf("%d",&ch);
	return (ch==1)? 1 : 0;
}
void createChildren(struct RightThreadedNode* root)
{
	if(isLChild(root->entry))
	{
		struct RightThreadedNode* newNode = (struct RightThreadedNode*)malloc(sizeof(struct RightThreadedNode));
		root->l = newNode;
		newNode->l = NULL;
		newNode->r = root;
		newNode->RightThread = 1;
		printf("\nEnter Left of %d: ",root->entry);
		scanf("%d",&newNode->entry);
		
	}
	if(isRChild(root->entry))
	{
		struct RightThreadedNode* newNode = (struct RightThreadedNode*)malloc(sizeof(struct RightThreadedNode));
		newNode->l = NULL;
		newNode->RightThread = 1;
		newNode->r = root->r;
		root->r = newNode;
		root->RightThread = 0;
		printf("\nEnter right of %d: ",root->entry);
		scanf("%d",&newNode->entry);
	}
	if(root->l != NULL)
		createChildren(root->l);
	if(root->RightThread == 0)
		createChildren(root->r);
}
int main()
{
	//creation of dummy node
	struct RightThreadedNode* dummy = (struct RightThreadedNode*)malloc(sizeof(struct RightThreadedNode));
	struct RightThreadedNode* root = (struct RightThreadedNode*)malloc(sizeof(struct RightThreadedNode));
	dummy->r = dummy;
	dummy->entry = -1;
	dummy->RightThread = 0;
	dummy->l = root;
	root->l = NULL;
	root->r = dummy;
	root->RightThread = 1;
	printf("Enter root node: ");
	scanf("%d",&root->entry);
	createChildren(root);
	printf("Inorder Traversal:\n");
	inorder(dummy);
	return 0;
}
