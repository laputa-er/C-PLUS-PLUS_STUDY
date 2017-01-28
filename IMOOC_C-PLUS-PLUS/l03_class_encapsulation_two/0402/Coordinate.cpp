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
