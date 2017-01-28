#include <iostream>
#include <stdlib.h>
#include "Teacher.h"
using namespace std;

// m_strName
void Teacher::setName(string _name)
{
    m_strName = _name;
}
string Teacher::getName()
{
    return m_strName;
}

// m_strGender
void Teacher::setGender(string _gender)
{
    m_strGender = _gender;
}
string Teacher::getGender()
{
    return m_strGender;
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
    Teacher t;
    t.setName("keating");
    t.setGender("male");
    t.setAge(42);

    cout << t.getName() << " " << t.getAge() << " " << t.getGender() << endl; // keating 42 male
    t.teach(); // having class...

    return 0;
}