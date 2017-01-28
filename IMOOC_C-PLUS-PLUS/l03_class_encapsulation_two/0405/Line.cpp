#include <iostream>
#include "Line.h"
using namespace std;
// 在构造函数中初始化对象指针
Line::Line(int x1, int y1, int x2, int y2)
{
    m_pCoorA = new Coordinate(x1, y1);
    m_pCoorB = new Coordinate(x2, y2);
    cout << "Line(int x1, int y1, int x2, int y2)" << endl;
}

// 在析构函数中回收对象指针指向的内存资源
Line::~Line()
{
    delete m_pCoorA;
    delete m_pCoorB;
    m_pCoorA = NULL;
    m_pCoorB = NULL;

    cout << "~Line()" << endl;
}

void Line::setA(int x, int y)
{
    m_pCoorA->setX(x);
    m_pCoorA->setY(y);
}

void Line::setB(int x, int y)
{
    m_pCoorB->setX(x);
    m_pCoorB->setY(y);
}

void Line::printInfo()
{
    cout << "(" << m_pCoorA->getX() << ", " << m_pCoorA->getY()<<")" << endl;
    cout << "(" << m_pCoorB->getX() << ", " << m_pCoorB->getY()<<")" << endl;
}