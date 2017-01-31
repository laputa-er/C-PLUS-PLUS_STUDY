#include <iostream>
#include "Node.h"
using namespace std;
Node::Node(int index, int data)
{
	this->index = index;
	this->data = data;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex)
{
	Node *temp = NULL;
	// 判断当前节点数据
	if(this->index == nodeIndex)
	{
		return this;
	}
	// 递归左节点数据
	if(this->pLChild != NULL)
	{
		temp = this->pLChild->SearchNode(nodeIndex);
		if(temp != NULL)
		{
			return temp;
		}
	}
	// 递归右节点数据
	if(this->pRChild != NULL)
	{
		temp = this->pRChild->SearchNode(nodeIndex);
		if(temp != NULL)
		{
			return temp;
		}
	}
	return NULL;
}

void Node::DeleteNode()
{
	if(this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	if(this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	if(this->pParent != NULL)
	{
		if(this->pParent->pLChild == this)
		{
			this->pParent->pLChild = NULL;
		}
		if(this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}
	}
	delete this;
}

void Node::PreorderTraversal()
{
	// 根
	cout << this->data << "(" << this->index << ")" << " ";
	// 左
	if(this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}
	// 右
	if(this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal()
{
	// 左
	if(this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();
	}
	// 根
	cout << this->data << "(" << this->index << ")" << " ";
	// 右
	if(this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()
{
	// 左
	if(this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}
	// 右
	if(this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	// 根
	cout << this->data << "(" << this->index << ")" << " ";
}