#include<stdio.h>
#include<stdlib.h>

struct BstNode
{
	struct BstNode *l,*r;
	int data;
};
//Insertion
struct BstNode* Insert(int dataIn,struct BstNode* root)
{
	if(root == NULL)
	{
		struct BstNode* newP = malloc(sizeof(struct BstNode));
		(*newP).l = (*newP).r = NULL;
		(*newP).data = dataIn;
		root = newP;
	}
	else if(dataIn <= (*root).data)
		(*root).l = Insert(dataIn,(*root).l);
	else if(dataIn > (*root).data)
		(*root).r = Insert(dataIn,(*root).r);
	return root;
}
//Auxillary function to return the reference of inorder successor
struct BstNode* InorderSuccessor(struct BstNode* root)
{
	while(root && (*root).l)
		root = (*root).l;
	return root;
}
//Deletion
struct BstNode* Delete(int dataDelete,struct BstNode* root)
{
	if(!root)
		printf("Node not found/Tree is Empty\n");
	if(dataDelete < (*root).data)
		(*root).l = Delete(dataDelete,(*root).l);
	else if(dataDelete > (*root).data)
		(*root).r = Delete(dataDelete,(*root).r);
	else if(dataDelete == (*root).data)//Node found,address all the three cases of deletion
	{
		if((*root).l == NULL && (*root).r == NULL)//Node to be deleted has no child nodes
		{
			free(root);
			root = NULL;
		}
		if((*root).l != NULL && (*root).r == NULL)//Node to be deleted has one left child
		{
			struct BstNode* leftSubTree = (*root).l;
			free(root);
			root = leftSubTree;
		}
		if((*root).l == NULL && (*root).r != NULL)//Node to be deleted has one right child
		{
			struct BstNode* rightSubTree = (*root).r;
			free(root);
			root = rightSubTree;
		}
		if((*root).l != NULL && (*root).r != NULL)//Node to be deleted has both left and right child
		{

			struct BstNode* InSucc = InorderSuccessor((*root).r);
			(*root).data = (*InSucc).data;
			(*root).r = Delete((*InSucc).data,(*root).r);
		}
	}
	return root;
}
//Traversal
void Inorder(struct BstNode* root)
{
	if(!root)return;
	Inorder((*root).l);
	printf("%d\t",(*root).data);
	Inorder((*root).r);
	return;
}
int main()
{
	struct BstNode* root = NULL;
	root = Insert(100,root);
	root = Insert(80,root);
	root = Insert(110,root);
	root = Insert(70,root);
	root = Insert(91,root);
	root = Insert(95,root);
	Inorder(root);
	root = Delete(80,root);
	Inorder(root);
	return 0;
}
