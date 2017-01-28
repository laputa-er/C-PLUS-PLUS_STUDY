#include <iostream>
#include "Coordinate.h"
using namespace std;

int main(void)
{
	// 创建对象指针
	Coordinate *p1 = new Coordinate;
	Coordinate *p2 = new Coordinate();

	// 对象数据成员赋值
	p1->m_iX = 10;
	p2->m_iY = 20;
	(*p1).m_iX = 30;
	(*p2).m_iY = 40;

	// 打印计算结果
	cout << p1-> m_iX + (*p2).m_iX << endl;
	cout << p1-> m_iY + (*p2).m_iY << endl;
	
	// 回收堆中的内存
	delete p1;
	p1 = NULL;

	delete p2;
	p2 = NULL;

	return 0;
}