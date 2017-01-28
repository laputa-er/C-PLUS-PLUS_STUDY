#include "MyQueue.h"
#include <iostream>
using namespace std;

// 构造函数
MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	ClearQueue();
	m_pQueue = new int[m_iQueueLen]; // 队列长度(注意：这里为了简化没有处理可能出现的内存分配失败)
}

// 析构函数
MyQueue::~MyQueue()
{
	delete []m_pQueue;
	m_pQueue = NULL;
}

// 清空队列
void MyQueue::ClearQueue()
{
	m_iHead = 0; // 队头下标
	m_iTail = 0; // 队尾下标
	m_iQueueLen = 0; // 队列长度
}

// 判空
bool MyQueue::QueueEmpty() const
{
	return m_iQueueLen == 0 ? true : false;
}

// 队列长度
int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

// 判满
bool MyQueue::QueueFull() const
{
	return m_iQueueLen == m_iQueueCapacity ? true : false;
}

// 从队尾插入新元素(需要顺时针移动队尾指针)
bool MyQueue::EnQueue(int element)
{
	if(QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity; // 实现环型的核心代码
		m_iQueueLen++;
		return true;
	}
}

// 从队首出队（需要顺时针移动队头指针）
bool MyQueue::DeQueue(int &element)
{
	if(QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity; // 实现环型的核心代码
		m_iQueueLen--;
		return true;
	}
}

// 遍历(从队头遍历到队尾)
void MyQueue::QueueTraverse()
{
	for(int i = 0; i < m_iQueueLen; i++)
	{
		cout << m_pQueue[(m_iHead + i) % m_iQueueCapacity] << endl;
	}
}

