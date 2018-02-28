#include "TreeNode.h"

TreeNode::TreeNode()
{
	leftNode = nullptr;
	rightNode = nullptr;
	value = NULL;
}


TreeNode::~TreeNode()
{
}

TreeNode * TreeNode::getLeft()
{
	return leftNode;
}

TreeNode * TreeNode::getRight()
{
	return rightNode;
}

void TreeNode::setLeft(TreeNode * node)
{
	leftNode = node;
}

void TreeNode::setRight(TreeNode * node)
{
	rightNode = node;
}

void TreeNode::setValue(char n)
{
	value = n;
}

char TreeNode::getValue()
{
	return value;
}
