#pragma once
#include <string>

using namespace std;

class TreeNode
{
public:
	TreeNode();
	~TreeNode();

	TreeNode * getLeft();
	TreeNode * getRight();
	void setLeft(TreeNode *);
	void setRight(TreeNode *);
	void setValue(char);
	char getValue();

private:
	TreeNode * leftNode;
	TreeNode * rightNode;
	char value;
};

