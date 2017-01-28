#include <iostream>
using namespace std;

template <class T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	// 使用模版函数
	int ival = max(100, 99); // 模版函数（自动推断类型）
	char cval = max<char>('a', 'b'); // 指定类型
	return 0;
}