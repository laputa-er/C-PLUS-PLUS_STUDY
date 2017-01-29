#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

// 重载 << 运算符
ostream &operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.m_iX << ", " << coor.m_iY << ")" << endl;
	return out;
}

// 重载 == 元算符
bool Coordinate::operator==(Coordinate &coor)
{
	return this->m_iX == coor.m_iX && this->m_iY == coor.m_iY;
}