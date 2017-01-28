#include <iostream>
#include <stdlib.h>
#include "Worker.h"
#include "Person.h"

using namespace std;

/*
* 定义 Person 类，要求有 m_strName 和 m_iAge 连个数据成员及构造函数和析构函数、eat 函数
* 定义 Worker 类，要求共有继承 Person 类，含有数据成员 m_iSalary、构造函数、析构函数、work 函数
*/
int main(void)
{
	Worker *p = new Worker();

	// 测试父类的成员
	p->m_strName = "Jim";
	p->m_iAge = 10;
	p->eat();

    // 测试自身的成员
	p->m_iSalary = 1000;
	p->work();

	cout << "p->m_strName:" << p->m_strName << endl;
	cout << "p->m_iAge:" << p->m_iAge << endl;
	cout << "p->m_iSalary:" << p->m_iSalary << endl;

	delete p;
	p = NULL;
	return 0;

	erson()
// Worker()
// eat()
// work()
// p->m_strName:Jim
// p->m_iAge:10
// p->m_iSalary:1000
// ~Worker()
// ~Person()
}