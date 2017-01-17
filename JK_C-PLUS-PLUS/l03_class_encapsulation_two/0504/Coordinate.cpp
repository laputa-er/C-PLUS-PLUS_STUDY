#include <iostream>
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y):m_iX(x),m_iY(y)
{
    cout << "Coordinate(int x, int y):m_iX(x),m_iY(y)" << endl;
}

Coordinate::~Coordinate()
{
    cout << "~Coordinate()" << endl;
}

int Coordinate::getX()
{
    return m_iX;
}

int Coordinate::getY()
{
    return m_iY;
}
void Coordinate::printInfo() const
{
    cout << "(" << m_iX << "," << m_iY << ")" << endl;
}