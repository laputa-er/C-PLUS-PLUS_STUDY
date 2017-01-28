#include <iostream>
using namespace std;

/*
* 索引运算符重载
*/
class Coordinate
{
public:
	Coordinate(int x, int y) {
		m_iX = x;
		m_iY = y;
	}
	// 重载索引运算符
	int operator[](int index)
	{
		if(0 == index)
		{
			return m_iX;
		}
		if(1 == index)
		{
			return m_iY;
		}
	}
private:
	int m_iX;
	int m_iY;
};

int main(void)
{
	Coordinate coor(3, 5);
	cout << coor[0]; // coor.operatorp[](0)
	cout << coor[1]; // coor.operatorp[](1)

	return 0;
}