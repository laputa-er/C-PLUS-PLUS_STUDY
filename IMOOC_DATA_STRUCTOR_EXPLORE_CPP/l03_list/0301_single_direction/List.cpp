#include <iostream>
#include "List.h"

List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	Node *currentNode = m_pList->next;
	while(NULL != currentNode)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List::ListEmpty()
{
	return m_iLength == 0 ? true : false;
}

int List::ListLength()
{
	return m_iLength;
}

bool List::GetElem(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	for(int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	pNode->next = currentNode->next;

	return true;
}

// 只能拿到第一个数据域匹配的节点
int List::LocateElem(Node *pNode)
{
	Node *currentNode = m_pList;
	for(int i = 0; i < m_iLength; i++)
	{
		currentNode = currentNode->next;
		if(currentNode->data== pNode->data)
		{
			return i;
		}
	}
	return -1;
}

bool List::PrevElem(Node *pCurrentNode, Node *pPreNode)
{
	Node *currentPrevNode = NULL;
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentPrevNode = currentNode;
		currentNode = currentNode->next;
		if(currentNode->data == pCurrentNode->data)
		{
			// 头节点不用来存储数据，因此不能作为符合条件的节点返回
			if(currentNode == m_pList)
			{
				return false;
			}
			pPreNode->data = currentPrevNode->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if(currentNode->data == pCurrentNode->data)
		{
			// 尾节点没有下一个节点了
			if(currentNode ->next ==  NULL)
			{
				return false;
			}
			pNextNode->data = currentNode->data;
			return true;
		}
	}
	return false;	
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

bool List::ListInsert(int i, Node *pNode)
{
	// 不能随便插入
	if(i < 0 || i > m_iLength)
	{
		return false;
	}
	// 找到插入位置的前一个节点
	Node *currentNode = m_pList;
	for(int k = 0; k < i; i++)
	{
		currentNode = currentNode->next;
	}
	// 创建新节点
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	// 插入
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	return true;
}

bool List::ListDelete(int i, Node *pNode)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	for(int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *temp = m_pList->next;
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return false;
}

bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	// 找到最后一个节点
	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	// 创建新节点
	Node *newNode = new Node;
	if(newNode == NULL)
	{
		return false;
	}
	// 初始化新节点
	newNode->next = NULL;
	newNode->data = pNode->data;
	// 插入
	currentNode->next = newNode;
	m_iLength--;
	return true;
}