#include <iostream>
#include <stdlib.h>
#include "Soldier.h"
using namespace std;

/*
* 定义 Person 类，要求有 m_strName 和 m_iAge 连个数据成员及构造函数和析构函数、eat 函数
* 定义 Worker 类，要求共有继承 Person 类，含有数据成员 m_iSalary、构造函数、析构函数、work 函数
*/
int main(void)
{
	Soldier soldier;
	soldier.play(); // 调用自身的 play
	soldier.Person::play(); // 调用父类的 play

	return 0;
}