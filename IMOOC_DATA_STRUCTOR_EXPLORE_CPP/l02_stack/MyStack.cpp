#include <iostream>
#include "MyStack.h"
using namespace std;

// 构造器（初始化）
MyStack::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[m_iSize];
	m_iTop = 0;
}

// 释放内存
MyStack::~MyStack()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

// 判空
bool MyStack::stackEmpty()
{
	return m_iTop == 0 ? true : false;
}

// 栈满
bool MyStack::stackFull()
{
	return m_iTop == m_iSize ? true : false;
}

// 清空栈
void MyStack::clearStack()
{
	m_iTop = 0;
}

// 获取栈的大小
int MyStack::stackLength()
{
	return m_iTop;
}

// 入栈
bool MyStack::push(char elem)
{
	if(stackFull())
	{
		return false; 
	}
	else
	{
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		return true;
	}
}

// 出栈
bool MyStack::pop(char &elem)
{
	if(stackEmpty())
	{
		return false;
	}
	else
	{
		m_iTop--;
		elem = m_pBuffer[m_iTop];
		return true;
	}
}

// 遍历
void MyStack::stackTraverse(bool isFromBottom)
{
	if (isFromBottom)
	{
		for(int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << endl;
		}
	}
	else
	{
		for(int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i] << endl;
		}
	}
}