#include <iostream>
#include <stdlib.h>
#include "Worker.h"
using namespace std;

/*
* 定义 Person 类，要求有 m_strName 和 m_iAge 连个数据成员及构造函数和析构函数、eat 函数
* 定义 Worker 类，要求共有继承 Person 类，含有数据成员 m_iSalary、构造函数、析构函数、work 函数
*/
int main(void)
{
	Worker worker;

	// 测试父类的成员
	// worker.m_strName = "Jim";
	// worker.m_iAge = 10;
	worker.eat();

    // 测试自身的成员
	worker.m_iSalary = 1000;
	worker.work();

	// cout << "worker.m_strName:" << worker.m_strName << endl;
	// cout << "worker.m_iAge:" << worker.m_iAge << endl;
	// cout << "worker.m_iSalary:" << worker.m_iSalary << endl;
	return 0;
}