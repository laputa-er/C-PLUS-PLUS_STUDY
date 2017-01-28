#include <iostream>
using namespace std;

/*
* 重载加号(成员函数重载)
*/
class Coordinate
{
	// 友元函数运算符重载声明
	friend ostream& operator<<(ostream &out, const Coordinate &coor);
public:
	Coordinate(int x, int y) {
		m_iX = x;
		m_iY = y;
	}
private:
	int m_iX;
	int m_iY;
};

// 友元函数<<号重载
ostream& operator<<(ostream &out, const Coordinate &coor)
{
	cout << coor.m_iX << ", " << coor.m_iY << endl;
	return out;
}

int main(void)
{
	Coordinate coor1(3, 5);
	cout << coor1 << endl;

	return 0;
}