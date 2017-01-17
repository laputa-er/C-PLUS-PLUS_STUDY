#include <iostream>
#include "Array.h"
using namespace std;

int main(void)
{
	Array arr1(5);
	Array arr2(arr1);

	cout << "arr1->" << arr1.printArr() << endl;
	cout << "arr2->" << arr2.printArr() << endl;
	return 0;
}
