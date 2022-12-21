#include<stdio.h>
#include<stdlib.h>

struct RTNode
{
	struct RTNode* left;
	int RT;//RT = 1 => thread
	int data;
	struct RTNode* right;
};
struct RTNode* createNode(int dataIn)
{
	struct RTNode* newNode = (struct RTNode*)malloc(sizeof(struct RTNode));
	newNode->data = dataIn;
	newNode->left = newNode->right = NULL;
	newNode->RT = 1;
	return newNode;
}
struct RTNode* Insert(int dataIn,struct RTNode* Head)
{
	if(dataIn <= Head->data)
	{
		if(Head->left == NULL)
		{
			struct RTNode* newNode = createNode(dataIn);
			newNode->right = Head;
			Head->left = newNode;
		}
		else Head->left = Insert(dataIn,Head->left);
	}
	else if(dataIn > Head->data)
	{
		if(Head->RT == 1)
		{
			struct RTNode* newNode = createNode(dataIn);
			newNode->right = Head->right;
			Head->right = newNode;
			Head->RT = 0;
		}
		else Head->right = Insert(dataIn,Head->right);
	}
	return Head;
}
void Inorder(struct RTNode* Head)
{
	if(Head->left == NULL)
	{
		printf("No nodes in the tree\n");
		return;
	}
	struct RTNode* current = Head->left;
	while(current != Head)
	{
		while(current->left)
			current = current->left;
		printf("%d\t",current->data);
		while(current->RT == 1 && current->right != Head)
		{
			current = current->right;
			printf("%d\t",current->data);
		}
		current = current->right;
	}
	return;
}
int main()
{
	//Creation of Header Node
	struct RTNode* Head = (struct RTNode*)malloc(sizeof(struct RTNode));
	//Initializing Head node
	Head->RT = 0;
	Head->data = 100;
	Head->right = Head;//Stores reference of itself
	Head->left = NULL;

	printf("Before Insertion Head = %p\n",Head);
	Head = Insert(50,Head);
	Head = Insert(40,Head);
	Head = Insert(69,Head);
	Head = Insert(44,Head);
	Head = Insert(30,Head);
	Head = Insert(-1,Head);
	printf("After Insertion Head = %p\n",Head);
	Inorder(Head);
	return 0;
}
