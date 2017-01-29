#include <iostream>
#include "MyStack.h"
using namespace std;

#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16

int main(void)
{
	char num[] = "0123456789ABCDE";
	MyStack<int> *pStack = new MyStack<int>(30); // 栈必须足够大

	// 使用短除法将十进制转换为十六进制
	int N = 2017;
	int mod = 0;
	while(N != 0)
	{
		mod = N % HEXADECIMAL;
		pStack->push(mod); // 栈中16进制的 A ~ E 部分还是用的十进制表示的
		N = N / HEXADECIMAL;
	}

	// 需要转换为16进制表示方式
	int elem = 0;
	while(!pStack->stackEmpty())
	{
		pStack->pop(elem);
		cout << num[elem];
	}

	delete pStack;
	pStack = NULL;

	return 0;
}
