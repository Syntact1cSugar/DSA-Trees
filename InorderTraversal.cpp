#include<iostream>
#include<stack>
using namespace std;
class BstNode
{
	public:
		BstNode* left;
		int info;
		BstNode* right;
		//Constructors
		BstNode(int info)
		{
			this->info = info;
			this->left = this->right = NULL;
		}
		BstNode(int info,BstNode* left,BstNode* right)
		{
			this->info = info;
			this->left = left;
			this->right = right;
		}
};
BstNode* Insert(int infoIn,BstNode* root)
{
	if(!root)
	{
		BstNode* newNode = new BstNode(infoIn);
		root = newNode;
	}
	else if(infoIn <= root->info)
		root->left = Insert(infoIn,root->left);
	else if(infoIn > root->info)
		root->right = Insert(infoIn,root->right);
	return root;
}
void InorderStack(BstNode* root)
{
	if(!root)
	{
		printf("No nodes the tree\n");
		return;
	}
	stack<BstNode*> S;
	while(root != NULL)
	{
		while(root != NULL)
		{
			S.push(root);
			root = (*root).left;
		}
		root = S.top();
		S.pop();
		cout << (*root).info << "\t";
		root = (*root).right;
		while(root == NULL && !S.empty())
		{
			root = S.top();
			S.pop();
			cout << (*root).info << "\t";
			root = (*root).right;
		}
	}
	return;
}
int main()
{
	BstNode* root = NULL;
	root = Insert(100,root);
	root = Insert(10,root);
	root = Insert(110,root);
	InorderStack(root);
	return 0;
}

