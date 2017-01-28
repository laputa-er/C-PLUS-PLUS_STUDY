#include <iostream>
#include "MyStack.h"

using namespace std;

int main(void)
{
	// 创建栈实例
	MyStack *pStack = new MyStack(5);

	// 判空
	if(pStack->stackEmpty())
	{
		cout << "栈为空" << endl;
	}

	// 入栈
	pStack->push('a'); // 底
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e'); // 顶

	// 栈长度
	cout << pStack->stackLength() << endl;


	// 判满
	if(pStack->stackFull())
	{
		cout << "栈为满" << endl;
	}

	// 出栈
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;

	// 遍历
	pStack->stackTraverse(true);

	delete pStack;
	pStack = NULL;
	return 0;
}