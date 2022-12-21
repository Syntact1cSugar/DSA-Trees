#include<iostream>
#include<stack>

//Declaration of expression tree node
class Node
{
	public:
		Node *left,*right;
		char symbol;
		Node(char symbol=' ',Node* left=NULL,Node* right=NULL)
		{
			this->symbol = symbol;
			this->left = left;
			this->right = right;
		}
};
//Tree Traversal
void preorder(Node* root)
{
	if(!root)return;
	std::cout << (*root).symbol << "\t";
	preorder((*root).left);
	preorder((*root).right);
	return;
	return;
}

bool isOperator(char c)
{
	switch(c)
	{
		case '*':
		case '/':
		case '+':
		case '-':
			return true;
	}
	return false;
}
bool isOperand(char c)
{
	return (c >= 'A' && c <= 'Z')? true : (c >= 'a' && c <= 'z')? true : false;
}

int precedence(char c)
{
	switch(c)
	{
		case '^':return 3;
		case '*':
		case '/':return 2;
		case '+':
		case '-':return 1;
	}
	return -1;
}

Node* constructTree(char* infix)
{
	std::stack<Node*> Operator;
	std::stack<Node*> Operand;
	for(int i=0;*(infix+i) != '\0';i++)
	{
		Node* newP = new Node(*(infix+i),NULL,NULL);
		if(*(infix+i) == '(')
			Operator.push(newP);
		else if(*(infix+i) == ')')
		{
			delete(newP);
			while((Operator.top())->symbol != '(')
			{
				(Operator.top())->right = Operand.top();
				Operand.pop();
				(Operator.top())->left = Operand.top();
				Operand.pop();
				Operand.push(Operator.top());
				Operator.pop();
			}
			delete(Operator.top());
			Operator.pop();
		}
		else if(isOperand(*(infix+i)))
			Operand.push(newP);
		else if(isOperator(*(infix+i)))
		{
			while(!Operator.empty() && precedence(*(infix+i)) <= precedence((Operator.top())->symbol))
			{
				Operator.top()->right = Operand.top();
				Operand.pop();
				Operator.top()->left = Operand.top();
				Operand.pop();
				Operand.push(Operator.top());
				Operator.pop();
			}
			Operator.push(newP);
		}
	}
	//Empty the stack
		while(!Operator.empty())
		{
			Operator.top()->right = Operand.top();
			Operand.pop();
			Operator.top()->left = Operand.top();
			Operand.pop();
			Operand.push(Operator.top());
			Operator.pop();
		}
	return Operand.top();
}
int main()
{
	char* infix = new char[20];
	std::cin >> infix;
	Node* root = constructTree(infix);
	preorder(root);
	return 0;
}
