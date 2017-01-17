#include <iostream>
using namespace std;

class Coordinate
{
public:
	// const 数据成员只能在初始化列表中赋值
	Coordinate(int x, int y):m_iX(x), m_iY(y)
	{
	}
private:
	const int m_iX;
	const int m_iY;
};

class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
private:
	const Coordinate m_coorA;
	const Coordinate m_coorB;
};

Line::Line(int x1, int y1, int x2, int y2):m_coorA(x1, y1), m_coorB(x2, y2)
{
}

int main(void)
{
	Line *p = new Line(2, 1, 6, 4);

	delete p;
	p = NULL;
	return 0;
}