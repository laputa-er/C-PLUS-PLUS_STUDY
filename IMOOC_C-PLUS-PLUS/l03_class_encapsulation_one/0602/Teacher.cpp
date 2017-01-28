#include <iostream>
#include <stdlib.h>
#include "Teacher.h"
using namespace std;

Teacher::Teacher()
{
    m_strName = "Jim";
    m_iAge = 5;
    cout << "Teacher()" << endl;
}

Teacher::Teacher(string name, int age)
{
    m_strName = name;
    m_iAge = age;
    cout << "Teacher(string name, int age)" << endl;
}

// m_strName
void Teacher::setName(string _name)
{
    m_strName = _name;
}
string Teacher::getName()
{
    return m_strName;
}

// m_iAge
void Teacher::setAge(int _age)
{
    m_iAge = _age;
}

int Teacher::getAge()
{
    return m_iAge;
}

void Teacher::teach()
{
    cout << "having class..." << endl;
}

int main(void)
{
    Teacher t1;
    Teacher t2("Merry", 15);
    Teacher t3("Sean");

    cout << t1.getName() << " " << t1.getAge() << endl;
    cout << t2.getName() << " " << t2.getAge() << endl;
    
    return 0;
}