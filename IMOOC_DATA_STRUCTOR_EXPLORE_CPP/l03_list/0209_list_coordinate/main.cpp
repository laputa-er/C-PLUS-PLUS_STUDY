#include <iostream>
#include "List.h"

using namespace std;

int main(void)
{
	Coordinate e1(3, 1);
	Coordinate e2(5, 1);
	Coordinate e3(7, 1);
	Coordinate e4(2, 1);
	Coordinate e5(9, 1);
	Coordinate e6(1, 1);
	Coordinate e7(8, 1);

	List *list1 = new List(10);
	list1->ListInsert(0, &e1);
	list1->ListInsert(0, &e2);
	list1->ListInsert(0, &e3);
	list1->ListInsert(0, &e4);
	list1->ListInsert(0, &e5);
	list1->ListInsert(0, &e6);
	list1->ListInsert(0, &e7);
	
	Coordinate temp(0, 0);
	list1->ListDelete(0, &temp);
	list1->ListTraverse();

	cout << "length:" << list1->ListLength() << endl;

	list1->GetElem(0, &temp);
	cout << "temp:" << temp << endl;

	delete list1;
	list1 = NULL;
	return 0;
}

