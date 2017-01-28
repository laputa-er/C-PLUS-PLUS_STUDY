#include <iostream>
#include "Array.h"
using namespace std;

Array::Array(int len)
{
	this->len = len;
}
Array::~Array()
{

}
int Array::getLen()
{
	return len;
}
Array& Array::setLen(int len)
{
	this->len = len;
	return *this;
}

Array& Array::printInfo()
{
	cout << "len = " << len << endl;
	return *this;
}