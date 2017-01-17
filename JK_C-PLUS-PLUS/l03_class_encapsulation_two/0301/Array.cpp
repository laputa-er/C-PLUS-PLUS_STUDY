#include <iostream>
#include "Array.h"
using namespace std;

// 构造函数
Array::Array(int count):m_iCount(count)
{
	cout << "Array()" << endl;
	m_pArr = new int[m_iCount];
	for(int i = 0; i < m_iCount; i++)
	{
		m_pArr[i] = i;
	}
}
// 析构函数
Array::~Array()
{
	delete []m_pArr;
	m_pArr = NULL;
	cout << "~Array()" << endl;
}
// 拷贝构造函数
Array::Array(const Array& array)
{
	cout << "Array(const Array& array)" << endl;
	m_iCount = array.m_iCount;
	m_pArr = new int[m_iCount];
	for(int i = 0; i < m_iCount; i++)
	{
		m_pArr[i] = array.m_pArr[i];
	}
}
void Array::printArr()
{
	// 打印数组在内存中的地址
	cout << "m_pArr:" << m_pArr << endl;
}
void Array::setCount(int count)
{
	m_iCount = count;
}

int Array::getCount()
{
	return m_iCount;
}
