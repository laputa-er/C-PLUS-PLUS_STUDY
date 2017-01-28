#include <string.h>
#include <iostream>
using namespace std;

// 单个类型
template <typename T>
void swapNum(T &a, T &b)
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

// 类型和数据
temolate <typename T, int size>
void display(T a)
{
	for(int i = 0; i < size; i++)
	{
		cout << a;
	}
	cout << endl;
}

int main(void)
{
	int x = 20, y = 30;
	swapNum<int>(x, y);

	int a = 1024;
	string str = "hello world!";
	display<int, string>(a, str);

	display<int, 5>(15);
	return 0;
}