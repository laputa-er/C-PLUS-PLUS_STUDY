#include "List.h"
#include <iostream>
using namespace std;

List::List(int size)
{
	m_iSize = size;
	m_pList = new Coordinate[m_iSize];
	m_iLength = 0;
}

List::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
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
bool List::GetElem(int i, Coordinate *e)
{
	if(i < 0 || i >= m_iSize)
	{
		return false;
	}
	*e = m_pList[i];
	return true;
}

int List::LocateElem(Coordinate *e)
{
	for(int i = 0; i < m_iLength; i++)
	{
		if(m_pList[i] == *e)
		{
			return i;
		}
	}
	return -1;
}

bool List::PrevElem(Coordinate *currentElem, Coordinate *preElem)
{
	int temp = LocateElem(currentElem);
	// 指定元素没有找到
	if(temp == -1)
	{
		return false;
	}
	else
	{
		// 载链表首位，没有前驱
		if(temp == 0)
		{
			return false;
		}
		else
		{
			*preElem = m_pList[temp - 1];
			return true;
		}
	}
}

bool List::NextElem(Coordinate *currentElem, Coordinate *nextElem)
{
	int temp = LocateElem(currentElem);
	if(temp == -1)
	{
		return false;
	}
	else
	{
		// 在链表尾部，没有后继
		if(temp == m_iLength - 1)
		{
			return false;
		}
		else
		{
			*nextElem = m_pList[temp + 1];
			return true;
		}
	}	
}

void List::ListTraverse()
{
	for(int i = 0; i < m_iLength; i++)
	{
		cout << m_pList[i] << endl;
	}
}

bool List::ListInsert(int i, Coordinate *e)
{
	// 不能随便插入
	if(i < 0 || i >= m_iSize)
	{
		return false;
	}
	// 移动
	for(int k = m_iLength - 1; k >= i; k--)
	{
		m_pList[k+1] = m_pList[k];
	}
	// 插入
	m_pList[i] = *e;
	// 长度加一
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, Coordinate *e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	// 获取要删除的元素
	*e = m_pList[i];

	// 从删除点往后的数据向前移动
	for(int k = i + 1; k > m_iLength; k++)
	{
		m_pList[k - 1] = m_pList[k];
	}
	// 长度减一
	m_iLength--;
	return true;
}
