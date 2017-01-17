#include <iostream>
#include <stdlib.h>

using namespace std;

// 坐标点
class Coordinate
{
public:
    Coordinate(int x, int y);
private:
    int m_iX;
    int m_iY;
};

// 线
class Line
{
public:
    Line(int x1, int y1, int x2, int y2);
private:
    Coordinate m_coorA;
    Coordinate m_coorB;
};


Coordinate::Coordinate(int x, int y):m_iX(x),m_iY(y)
{
    cout << "Coordinate(int x, int y):m_iX(x),m_iY(y)" << endl;
}

Line::Line(int x1, int y1, int x2, int y2):m_coorA(x1, y1),m_coorB(x2, y2)
{
    cout << "Line(int x1, int y1, int x2, int y2):m_coorA(x1, y1),m_coorB(x2, y2)" << endl;
}

int main(void)
{
    Line *p = new Line(2, 1, 6, 4);

    delete p;
    p = NULL;
    
    return 0;
}