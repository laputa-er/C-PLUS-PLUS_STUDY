#include <iostream>
#include "List.h"

using namespace std;

int main(void)
{
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;

	List *list1 = new List(10);
	list1->ListInsert(0, &e1);
	list1->ListInsert(0, &e2);
	list1->ListInsert(0, &e3);
	list1->ListInsert(0, &e4);
	list1->ListInsert(0, &e5);
	list1->ListInsert(0, &e6);
	list1->ListInsert(0, &e7);
	
	int temp = 0;
	list1->ListDelete(0, &temp);
	list1->ListTraverse();

	cout << "length:" << list1->ListLength() << endl;

	list1->GetElem(0, &temp);
	cout << "temp:" << temp << endl;

	delete list1;
	list1 = NULL;
	return 0;
}

