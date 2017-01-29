#include <iostream>
#include "MyStack.h"
#include "Coordinate.h"
using namespace std;

int main(void)
{
	// 创建栈实例
	MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);

	// 判空
	if(pStack->stackEmpty())
	{
		cout << "栈为空" << endl;
	}

	// 入栈
	pStack->push(Coordinate(1, 1)); // 底
	pStack->push(Coordinate(1, 2));
	pStack->push(Coordinate(1, 3));
	pStack->push(Coordinate(1, 4));
	pStack->push(Coordinate(1, 5)); // 顶

	// 栈长度
	cout << pStack->stackLength() << endl;


	// 判满
	if(pStack->stackFull())
	{
		cout << "栈为满" << endl;
	}

	// 出栈
	Coordinate elem;
	pStack->pop(elem);

	// 遍历
	pStack->stackTraverse(true);

	delete pStack;
	pStack = NULL;
	return 0;
}