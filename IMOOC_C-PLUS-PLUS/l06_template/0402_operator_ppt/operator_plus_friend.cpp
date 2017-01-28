#include <iostream>
using namespace std;

/*
* 重载加号(成员函数重载)
*/
class Coordinate
{
	// 声明友元函数运算符重载
	friend Coordinate operator+(const Coordinate &c1, const Coordinate &c2);
public:
	Coordinate(int x, int y) {
		m_iX = x;
		m_iY = y;
	}
private:
	int m_iX;
	int m_iY;
};

// 友元函数+号重载
Coordinate operator+(const Coordinate &c1, const Coordinate &c2)
{
	Coordinate temp(0, 0);
	temp.m_iX = c1.m_iX + c2.m_iX;
	temp.m_iY = c1.m_iY + c2.m_iY;

	return temp;
}
int main(void)
{
	Coordinate coor1(3, 5);
	Coordinate coor2(1, 1);
	Coordinate coor3(0, 0);
	coor3 = coor1 + coor2; // coor1.operator+(coor2)

	return 0;
}