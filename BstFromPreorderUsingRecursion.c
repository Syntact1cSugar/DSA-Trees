#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *right,*left;
};
void inorder(struct Node* root)
{
	if(!root) return;
	inorder((*root).left);
	printf("%d\t",(*root).data);
	inorder((*root).right);
	return;
}
void preorder(struct Node* root)
{
	if(!root)return;
	printf("%d\t",(*root).data);
	preorder((*root).left);
	preorder((*root).right);
	return;
}
struct Node* constructTree(int* Preorder,int low,int high)
{
	if(!Preorder || low > high)return NULL;
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	(*root).data = *(Preorder+low);
	(*root).left = (*root).right = NULL;
	if(low == high)return root;
	int highIndex = high+1;
	for(int i=low;i<=high;i++)
		if(*(Preorder+i) > *(Preorder+low))
		{
			highIndex = i;
			break;
		}
	root->left = constructTree(Preorder,low+1,highIndex-1);
	root->right = constructTree(Preorder,highIndex,high);
	return root;
}
int main()
{
	int *Preorder,n;
	printf("Number of nodes : ");
	scanf("%d",&n);
	Preorder = (int*)malloc(sizeof(int)*n);
	printf("\nPreorder : ");
	for(int i=0;i<n;i++)
		scanf("%d",Preorder+i);
	struct Node* root = constructTree(Preorder,0,n-1);
	printf("\nInorder Traversal :\t");
	inorder(root);
	printf("\nPreorder Traversal :\t");
	preorder(root);
	return 0;
}
