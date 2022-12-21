#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	struct TreeNode *right,*left;
	char symbol;
};
struct StackNode
{
	struct TreeNode* TreeNodeAddr;
	struct StackNode* next;
} 
*top = NULL;
/**Stack Implementation using singly linked list**/
int isEmpty()
{
	return (!top)? 1 : 0;
}
int isFull()
{
	struct StackNode* testP = (struct StackNode*)malloc(sizeof(struct StackNode));
	if(!testP)return 1;
	else free(testP);
	return 0;
}
int Push(struct TreeNode* AddrIn)
{
	if(isFull())return 0;
	struct StackNode* newP = (struct StackNode*)malloc(sizeof(struct StackNode));
	newP->TreeNodeAddr = AddrIn;
	newP->next = top;
	top = newP;
	return 1;
}
int Pop()
{
	if(isEmpty())return 0;
	struct StackNode* deleteP = top;
	top = top->next;
	free(deleteP);
	return 1;
}
struct TreeNode* Top()
{
	if(isEmpty())return NULL;
	return top->TreeNodeAddr;
}
/**End of Stack Implementation**/
//Auxillary functions to determine the type of symbol
int isOperand(char c)
{
	return (c >= 'A' && c <= 'Z')? 1 : (c >= 'a' && c <= 'z')? 1 : 0;
}
int isOperator(char c)
{
	if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
		return 1;
	return 0;
}
//Function to create Expression Tree  
struct TreeNode* CreateExpressionTree(char* postfix)
{
	struct TreeNode* root = NULL;
	for(int i=0;*(postfix+i)!='\0';i++)
	{
		root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		root->symbol = *(postfix+i);
		root->right = root->left = NULL;
		if(isOperand(*(postfix+i)))
			Push(root);
		else if(isOperator(*(postfix+i)))
		{
			root->right = Top();
			Pop();
			root->left = Top();
			Pop();
			Push(root);
		}
	}
	root = Top();
	Pop();
	return root;
}
//Function to evaluate Expression Tree
float eval(struct TreeNode* root)
{
	if(isOperand(root->symbol))
	{
		float value;
		printf("\nValue of %c : ",root->symbol);
		scanf("%f",&value);
		return value;
	}
	else if(isOperator(root->symbol))
	{
		if(root->symbol == '/')
			return eval(root->left)/eval(root->right);
		else if(root->symbol == '*')
			return eval(root->left)*eval(root->right);
		else if(root->symbol == '+')
			return eval(root->left)+eval(root->right);
		else if(root->symbol == '-')
			return eval(root->left)-eval(root->right);
	}
	return 0.0;//Just in case to terminate the recurrsion 
}
//Traversal
void Inorder(struct TreeNode* root)
{
	if(!root)return;
	Inorder(root->left);
	printf("%c",root->symbol);
	Inorder(root->right);
	return;
}
int main()
{
	char* postfix = (char*)malloc(sizeof(char)*20);
	printf("Posfix Expresion : ");
	scanf("%s",postfix);
	struct TreeNode* root = CreateExpressionTree(postfix);
	printf("\nInfix Expression : ");
	Inorder(root);
	float result = eval(root);
	printf("\nResult of Expression : %-5.2f\n",result);
	return 0;
}
