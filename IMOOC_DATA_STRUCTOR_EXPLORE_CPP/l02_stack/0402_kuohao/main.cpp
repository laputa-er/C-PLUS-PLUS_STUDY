#include <iostream>
#include "MyStack.h"
using namespace std;

int main(void)
{
	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[()([()()()])]";
	char currentNeed = 0;

	for(int i = 0; i < strlen(str); i++)
	{
		cout << i << endl;
		if(str[i] == currentNeed)
		{
			char elem;
			pStack->pop(elem);

			// 需要匹配的都匹配尽了，则将 currentNeed 置为 0，后面还有就是多余的
			if(!pNeedStack->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
		else
		{
			pStack->push(str[i]);
			switch(str[i])
			{
				case '[':
					// 如果当前有字符在期待匹配之前出现的字符，就将它入栈
					if(0 != currentNeed)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ']';
					break;
				case '(':
					if(0 != currentNeed)
					{
						pNeedStack->push(currentNeed);
					}
					currentNeed = ')';
					break;
				default:
					cout << "括号不匹配" << endl;
					return 0;
			}
		}
	}
	if(pStack->stackEmpty())
	{
		cout << "括号匹配" << endl;
	}
	else
	{
		cout << "括号不匹配" << endl;
	}

	delete pStack;
	pStack = NULL;
	delete pNeedStack;
	pNeedStack = NULL;

	return 0;
}
