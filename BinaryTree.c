#include<stdio.h>
#include<stdlib.h>
struct BinaryNode
{
	char data;
	struct BinaryNode *left,*right;
};
void inorder(struct BinaryNode* root)
{
	if(!root)return;
	inorder(root->left);
	printf("%c\t",root->data);
	inorder(root->right);
}
void preorder(struct BinaryNode* root)
{
	if(!root)return;
	printf("%c\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct BinaryNode* root)
{
	if(!root)return;
	postorder(root->left);
	postorder(root->right);
	printf("%c\t",root->data);
}
int isLChild(char data)
{
	int ch;
	printf("\nLeft Child of %c? : ",data);
	scanf("%d",&ch);
	return ch;
}
int isRChild(char data)
{
	int ch;
	printf("\nRight Child of %c? : ",data);
	scanf("%d",&ch);
	return ch;
}
void createChildren(struct BinaryNode* root)
{
	if(!root)return;
	if(isLChild(root->data))
	{
		root->left = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
		printf("\nLeft Data of %c : ",root->data);
		scanf(" %c",&(root->left->data));
	}
	else root->left = NULL;
	if(isRChild(root->data))
	{
		root->right = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
		printf("\nRight Data of %c : ",root->data);
		scanf(" %c",&(root->right->data));
	}
	else root->right = NULL;
	createChildren(root->left);
	createChildren(root->right);
}
int main()
{
	struct BinaryNode* root = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
	root->left = root->right = NULL;
	printf("Root Data : ");
	scanf(" %c",&root->data);
	createChildren(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	return 0;
}
