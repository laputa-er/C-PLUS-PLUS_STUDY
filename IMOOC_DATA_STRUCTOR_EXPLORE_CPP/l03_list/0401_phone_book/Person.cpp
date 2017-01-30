#include "Person.h"
#include <iostream>
#include <ostream>
using namespace std;

// 重载赋值运算符
Person &Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

// 重载判等运算符
bool Person::operator==(Person &person)
{
	cout << "this->name == person.name:" << (this->name == person.name) << endl;
	cout << "this->phone == person.phone:" << (this->phone == person.phone) << endl;
	return (this->name == person.name && this->phone == person.phone);
}

// 重载输出运算符
ostream &operator<<(ostream &out, Person &person)
{
	out << person.name << "-----" << person.phone << endl;
	return out;
}