#include <iostream>
#include "MyArray.h"
using namespace std;

int main(void)
{
	MyArray<int, 5, 0> arr;
	arr.display();
	
	return 0;
}