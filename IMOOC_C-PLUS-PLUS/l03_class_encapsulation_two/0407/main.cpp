#include <iostream>
#include "Array.h"

using namespace std;

int main(void)
{
	Array arr1(1);
	// 链式调用
	arr1.printInfo().setLen(2).printInfo();
	return 0;
}