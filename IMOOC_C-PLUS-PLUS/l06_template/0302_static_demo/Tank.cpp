#include <iostream>
#include "Tank.h"
using namespace std;

// 静态数据成员（在构造函数外初始化）
int Tank::s_iCount = 0;

Tank::Tank(char code)
{
	m_cCode = code;
	s_iCount++;
	cout << "Tank" << endl;
}

Tank::~Tank()
{
	s_iCount--;
	cout << "~Tank()" << endl;
}

void Tank::fire()
{
	cout << "Tank -- fire" << endl;
}

// 静态成员函数（只能访问静态数据成员，实现和非静态成员函数没有区别）
int Tank::getCount()
{
	return s_iCount;
}