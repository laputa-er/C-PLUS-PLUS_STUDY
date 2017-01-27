#include <iostream>
using namespace std;

/*
* 重载++
*/
class Coordinate
{
public:
	Coordinate(int x, int y)
	{
		m_iX = x;
		m_iY = y;
	}
	// 前置++
	Coordinate& operator++()
	{
		m_iX++;
		m_iY++;
		return *this;
	}
	// 后置 ++(参数 int 表示这是后置重载)
	Coordinate operator++(int)
	{
		// 保存当前值对象(old 是默认的拷贝构造函数)
		Coordinate old(*this);
		m_iX++;
		m_iY++;

		// 返回的时修改前的对象
		return old;
	}
private:
	int m_iX;
	int m_iY;
};

int main(void)
{
	Coordinate coor1(3, 5);
	coor1++; // coor1.operator++(0) // 参数0没有什么用，计算机以此识别这时一个后置运算
	++coor1; // coor1.operator++()
	return 0;
}