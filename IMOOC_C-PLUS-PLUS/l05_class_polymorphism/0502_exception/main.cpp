#include <iostream>
#include <stdlib.h>
#include "Exception.h"
#include "IndexException.h"
using namespace std;

void test()
{
	throw IndexException();
}
int main(void)
{
	try
	{
		test();
	}
	catch(Exception &e)
	{
		e.printException();
	}
	catch(...)
	{
		cout << "Exception" << endl;
	}
	return 0;
}