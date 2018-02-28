// ArithmeticExpressionTrees.cpp
//Tyler Owens
//March 2, 2017

#include "stdafx.h"
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <stack>

int A = 2;
int B = 7;
int C = 3;
int D = 5;
string expression = "ABC+*D/";

//Search expression tree and output it in postfix notation
void Postfix(TreeNode * root);
//Calculate result of expression tree
double Evaluate(TreeNode * root);

int main()
{
	using namespace std;

	stack <TreeNode *> treeStack;

	//Generate expression tree
	for (string::iterator it = expression.begin(); it != expression.end(); ++it)
	{
		if (isalpha(*it))
		{
			TreeNode * node = new TreeNode();
			node->setValue(*it);
			treeStack.push(node);
		}
		else
		{
			TreeNode * node = new TreeNode();
			node->setValue(*it);
			node->setRight(treeStack.top());
			treeStack.pop();
			node->setLeft(treeStack.top());
			treeStack.pop();
			treeStack.push(node);
		}
		
	}
	TreeNode * root = treeStack.top();
	treeStack.pop();
	cout << "Postfix Expression = ";
	Postfix(root);
	cout << endl;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
	cout << "D = " << D << endl;
	cout << "Answer = " << Evaluate(root) << endl;

    return 0;
}

void Postfix(TreeNode * root)
{
	if (root != NULL)
	{
		Postfix(root->getLeft());
		Postfix(root->getRight());
		cout << root->getValue();
	}
}

double Evaluate(TreeNode * node)
{
	if (node->getLeft() == nullptr && node->getRight() == nullptr)
	{
		switch (node->getValue())
		{
		case 'A':
			return A;
		case 'B':
			return B;
		case 'C':
			return C;
		case 'D':
			return D;
		default:
			return 0;
		} 
	}
	else
	{
		double answer = 0.0;
		double left = Evaluate(node->getLeft());
		double right = Evaluate(node->getRight());
		char op = node->getValue();

		switch (op)
		{
		case '+':
			answer = left + right;
			break;
		case '-':
			answer = left - right;
			break;
		case '*':
			answer = left * right;
			break;
		case '/':
			answer = left / right;
			break;
		}

		return answer;
	
	}
}
