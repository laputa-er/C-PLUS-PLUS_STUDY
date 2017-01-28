#include <iostream>
using namespace std;

class Circle;

// 坐标
class Coordinate
{
	// Circle 类实例可以访问 Coordinate 实例中的私有成员
	friend Circle;
public:
	Coordinate(int x, int y);
private:
	int m_iX;
	int m_iY;
};

// 圆
class Circle
{
public:
	void printXY()
	{
		cout << m_coor.m_iX << m_coor.m_iY << endl;
	}
private:
	Coordinate m_coor;
};

int main(void)
{
	return 0;
}

