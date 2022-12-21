#include<stdio.h>
#include<stdlib.h>

/**Declaration of Tree Node*/
typedef struct Node
{
	int data;
	struct Node *l,*r;
}NODE;
/**Start of Stack Implementation*/
typedef struct stack
{
	NODE** A;
	int top;
	int size;
}
STACK;
STACK* createStack(int size)
{
	STACK* newS = (STACK*)malloc(sizeof(STACK));
	newS->top = -1;
	newS->size = size;
	newS->A = (NODE**)malloc(sizeof(NODE*)*newS->size);
	return newS;
}
int isEmpty(STACK* S)
{
	if(S->top == -1)return 1;
	return 0;
}
int isFull(STACK* S)
{
	if(S->top == S->size-1)return 1;
	return 0;
}
int Push(STACK* S,NODE* nodeIn)
{
	if(isFull(S))return 0;
	*(S->A + ++(S->top)) = nodeIn;
	return 1;
}
int Pop(STACK* S)
{
	if(isEmpty(S))return 0;
	(S->top)--;
	return 1;
}
NODE* Top(STACK* S)
{
	if(isEmpty(S))return NULL;
	return *(S->A+S->top);
}	
STACK* destroyStack(STACK* S)
{
	if(S)
	{
		free(S->A);
		free(S);
		S = NULL;
	}
	return S;
}
/**End of Stack Implementation*/

/**Function to create tree from preoder*/

NODE* ConstructTree(int* preorder,int n)
{
	STACK* S = createStack(n);
	NODE* root = (NODE*)malloc(sizeof(NODE));
	root->data = preorder[0];
	root->r = root->l = NULL;
	Push(S,root);
	for(int i=1;i<n;i++)
	{

		NODE* curr = NULL;
		//Create new node for the next entry(that happens to be the root temp.)
		NODE* newP = (NODE*)malloc(sizeof(NODE));
		newP->r = newP->l = NULL;
		newP->data = *(preorder+i);
		while(!isEmpty(S) && *(preorder+i) > Top(S)->data)
		{
			curr = Top(S);
			Pop(S);
		}
		if(curr)//Insert right(for the appropiate node)
			curr->r = newP;
		else//Insert left(for the current leaf node)
			Top(S)->l = newP;
		Push(S,newP);
	}
	destroyStack(S);
	return root;
}
//Tree Traversals
void Inorder(NODE* root)
{
	if(!root)return;
	Inorder(root->l);
	printf("%d\t",root->data);
	Inorder(root->r);
	return;
}
int main()
{
	int n,*preorder;
	printf("Number of entries : ");
	scanf("%d",&n);
	preorder = (int*)malloc(sizeof(int)*n);
	printf("Preorder Traversal : ");
	for(int i=0;i<n;i++)
		scanf("%d",preorder+i);
	NODE* root = ConstructTree(preorder,n);
	Inorder(root);
	return 0;
}
