#include <iostream>
#include <stdlib.h>
#include "Teacher.h"
using namespace std;

// 构造函数（使用了初始化列表）
Teacher::Teacher(string name, int age, int m):m_strName(name), m_iAge(age), m_iMax(m)
{
    cout << "Teacher(string name, int age)" << endl;
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
    Teacher t1("Xiaoli", 26, 100);
    cout << t1.getName() << " " << t1.getAge() << " " << t1.getMax() << endl; // Xiaoli 26 100
    
    return 0;
}