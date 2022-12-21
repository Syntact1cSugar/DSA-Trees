#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *left,*right;
	int data;
};
void preorder(struct Node *root)
{
	if(!root)return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}
struct Node* constructTreeUtil(int* postorder,int low,int high)
{
	if(low > high)return NULL;
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root->data = *(postorder+high);
	root->left = root->right = NULL;
	if(low == high)return root;
	int i = high;
	while(i >= low && *(postorder+i-1) > *(postorder+high))
		i--;
	root->left = constructTreeUtil(postorder,low,i-1);
	root->right = constructTreeUtil(postorder,i,high-1);
	return root;
}
struct Node* constructTree(int* postorder,int n)
{
	struct Node* root = constructTreeUtil(postorder,0,n-1);
	return root;
}


int main()
{
	int n;
	printf("Number of nodes : ");
	scanf("%d",&n);
	int* postorder = (int*)malloc(sizeof(int)*n);
	printf("\nPostorder : ");
	for(int i=0;i<n;i++)
		scanf("%d",postorder+i);
	struct Node* root = constructTree(postorder,n);
	preorder(root);
	return 0;
}
