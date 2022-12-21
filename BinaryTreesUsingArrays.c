#include<stdio.h>
#include<stdlib.h>
int lChild(int n)
{
	int ch;
	printf("\nLeft Child of %d ? ",n);
	scanf("%d",&ch);
	return (ch==1)? 1 : 0;
}
int rChild(int n)
{
	int ch;
	printf("\nRight Child of %d ? : ",n);
	scanf("%d",&ch);
	return (ch==1)? 1 : 0;
}
int* createBinaryTree(int n)
{
	n = (2*n+1);
	int i;
	int* root = (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		*(root+i) = -1;
	printf("Enter the root Node: ");
	scanf("%d",root);
	for(i=0;i<n;i++)
	{
		if(*(root+i) == -1)continue;
		if(lChild(*(root+i)))
		{
			printf("Enter the left child of %d: ",*(root+i));
			scanf("%d",(root+(2*i+1)));
		}
		else *(root+(2*i+1)) = -1;
		if(rChild(*(root+i)))
		{	
			printf("Enter the right chid of %d: ",*(root+i));
			scanf("%d",(root+(2*i+2)));
		}
		else *(root+(2*i+2)) = -1;
	}
	return root;
}
void showTree(int* root,int n)
{
	if(!root)return;
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",*(root+i));
	printf("\n");
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	int* root = createBinaryTree(n);
	showTree(root,n);
	return 0;
}
