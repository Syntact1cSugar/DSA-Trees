#include<stdio.h>
#include<stdlib.h>
struct Node
{
	char key;
	struct Node *left,*right;
};
int top = -1;
struct Node* Stack[20];
void Push(struct Node* t)
{
	Stack[++top] = t;
	return;
}
struct Node* Pop()
{
	return Stack[top--];
}
int isOperator(char data)
{
	switch(data)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
	}
	return 0;
}
int isOperand(char data)
{
	if((data >= 'A' && data <= 'Z') || (data >= 'a' && data <= 'z'))
		return 1;
	return 0;
}
void createExpressionTree(char* c)
{
	if(*c == '\0')return;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->key = *c;
	newNode->left = newNode->right = NULL;
	if(isOperator(*c))
	{
		newNode->right = Pop();
		newNode->left = Pop();
		Push(newNode);
	}
	else if(isOperand(*c))
	{
		Push(newNode);
	}
	return createExpressionTree(++c);
}
void inorder(struct Node* root)
{
	if(!root)return;
	inorder(root->left);
	printf("%c\t",root->key);
	inorder(root->right);
}
float evaluateTree(struct Node* root)
{
	if(!root)return 0.0;
	if(isOperand(root->key))
	{
		float n;
		printf("\nEnter the value of %c : ",root->key);
		scanf("%f",&n);
		return n;
	}
	switch(root->key)
	{
		case '*' : return evaluateTree(root->left) * evaluateTree(root->right);
			   break;
		case '/' : return evaluateTree(root->left) / evaluateTree(root->right);
			   break;
		case '+' : return evaluateTree(root->left) + evaluateTree(root->right);
			   break;
		case '-' : return evaluateTree(root->left) - evaluateTree(root->right);
			   break;
	}
	return 0.0;
}
int main()
{
	char* postfix = (char*)malloc(sizeof(char)*20);
	scanf("%s",postfix);
	createExpressionTree(postfix);
	struct Node* root = Pop();
	printf("Infix Expression\n");
	inorder(root);
	float result = evaluateTree(root);
	printf("Result = %-5.2f",result);
	return 0;
}
