#include <string.h>
#include <iostream>
using namespace std;

// 单个类型
template <typename T>
void swapNum(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// 多个类型
template <typename T, typename C>
void display(T a, C b)
{
	cout << a << " " << b << endl;
}

int main(void)
{
	int x = 20, y = 30;
	swapNum<int>(x, y);

	int a = 1024;
	string str = "hello world!";
	display<int, string>(a, str);
	return 0;
}