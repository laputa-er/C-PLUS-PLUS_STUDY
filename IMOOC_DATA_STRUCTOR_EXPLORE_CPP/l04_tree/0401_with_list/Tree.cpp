#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree()
{
	m_pRoot = new Node();
}

Tree::~Tree()
{
	// DeleteNode(0, NULL);
	m_pRoot->DeleteNode();
}
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	// 要挂载的位置不存在
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	// 创建挂载上去的节点
	Node *node = new Node();
	// 申请空间失败
	if(node == NULL)
	{
		return false;
	}
	node->index = pNode->index;
	node->data = pNode->data;
	node->pParent = temp;

	if(direction == 0)
	{
		temp->pLChild = node;
	}
	if(direction == 1)
	{
		temp->pRChild = node;
	}
	return true;
}

Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if(temp == NULL)
	{
		return false;
	}
	if(pNode != NULL)
	{
		pNode->data = temp->data;
	}
	temp->DeleteNode();	
	return true;
}

void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
	cout << endl;
}

void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
	cout << endl;
}

void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
	cout << endl;
}