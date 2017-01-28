#include <iostream>
using namespace std;

/*
* 负号重载
*/
class Coordinate
{
public:
	Coordinate(int x, int y) {
		m_iX = x;
		m_iY = y;
	}
	// 重载负号（-）
	Coordinate& operator-()
	{
		m_iX = -m_iX;
		m_iY = -m_iY;
		return *this;
	}
private:
	int m_iX;
	int m_iY;
};

int main(void)
{
	Coordinate coor1(3, 5);
	-coor1; // coor1.operator-()

	return 0;
}