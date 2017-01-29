#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

// 重载 << 运算符
ostream &operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.m_iX << ", " << coor.m_iY << ")" << endl;
	return out;
}