#include <iostream>
using namespace std;

/*
* 负号重载
*/
class Coordinate
{
	// 重载负号（-）
	friend Coordinate& operator-(Coordinate &coor);
public:
	Coordinate(int x, int y)
	{
		m_iX = x;
		m_iY = y;
	}
private:
	int m_iX;
	int m_iY;
};

Coordinate& operator-(Coordinate &coor)
{
	coor.m_iX = -coor.m_iX;
	coor.m_iY = -coor.m_iY;
	return coor;
}

int main(void)
{
	Coordinate coor1(3, 5);
	-coor1; // coor1.operator-(coor1)

	return 0;
}