#include <iostream>
#include <stdlib.h>
#include "Teacher.h"
using namespace std;

// 构造函数（使用了初始化列表）
Teacher::Teacher(string name, int age, int m):m_strName(name), m_iAge(age), m_iMax(m)
{
    cout << "Teacher(string name, int age)" << endl;
}
Teacher::Teacher(const Teacher &tea):m_iMax(100)
{
    cout << "Teacher(const Teacher &tea)" << endl;
}
Teacher::~Teacher()
{
    cout << "~Teacher()" << endl;
}
void Teacher::setName(string _name)
{
    m_strName = _name;
}
string Teacher::getName()
{
    return m_strName;
}

void Teacher::setAge(int _age)
{
    m_iAge = _age;
}

int Teacher::getAge()
{
    return m_iAge;
}

int Teacher::getMax()
{
    return m_iMax;
}

int main(void)
{
    Teacher t1("Xiaoli", 26, 100); // 栈中定义对象(整个程序结束时,调用析构函数)

    Teacher *t2 = new Teacher(); // 堆中定义对象
    delete t2; // t2 析构函数被调用
    t2 = NULL;

    return 0;
}