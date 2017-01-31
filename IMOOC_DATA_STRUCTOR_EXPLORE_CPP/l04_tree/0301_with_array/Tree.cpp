#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree(int size, int *pRoot)
{
	m_iSize = size;
	m_pTree = new int[size];
	for(int i = 0; i < size; i++)
	{
		m_pTree[i] = 0;
	}
	m_pTree[0] = *pRoot;
}

Tree::~Tree()
{
	delete m_pTree;
	m_pTree = NULL;
}

int *Tree::SearchNode(int nodeIndex)
{
	// 下标不在有效范围内
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return NULL;
	}
	// 值为 0 代表没有节点
	if(m_pTree[nodeIndex] == 0)
	{
		return NULL;
	}
	return &m_pTree[nodeIndex];
}

/*
* param{int} nodeIndex 要插入哪个节点下面
* param{int} direction 0 左节点，1 右节点
* param{int *} pNode 要插入的节点的指针
* return{bool} true 插入成功， false 插入失败
*/
bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
	// 下标不在有效范围内
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	// 要插入的地方的父节点不存在
	if(m_pTree[nodeIndex] == 0)
	{
		return false;
	}

	// 如果作为左节点插入
	if(direction == 0)
	{
		int leftChildIndex = nodeIndex * 2 + 1;
		if(leftChildIndex >= m_iSize)
		{
			return false;
		}
		// 左子节点已经有数据了
		if(m_pTree[leftChildIndex] != 0)
		{
			return false;
		}
		m_pTree[leftChildIndex] = *pNode;
	}

	// 如果作为右节点插入
	if(direction == 1)
	{
		int rightChildIndex = nodeIndex * 2 + 2;
		if(rightChildIndex >= m_iSize)
		{
			return false;
		}
		// 左子节点已经有数据了
		if(m_pTree[rightChildIndex] != 0)
		{
			return false;
		}
		m_pTree[rightChildIndex] = *pNode;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, int *pNode)
{
	// 节点下标不在合法范围中
	if(nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	// 没有这个节点
	if(m_pTree[nodeIndex] == 0)
	{
		return false;
	}
	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}

void Tree::TreeTraverse()
{
	for(int i = 0; i < m_iSize; i++)
	{
		cout << m_pTree[i] << " ";
	}
	cout << endl;
}