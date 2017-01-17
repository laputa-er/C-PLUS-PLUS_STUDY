#include <iostream>
#include "Line.h"
using namespace std;
// 在构造函数中初始化对象指针
Line::Line(int x1, int y1, int x2, int y2):m_coorA(x1, y1), m_coorB(x2, y2)
{
    cout << "Line(int x1, int y1, int x2, int y2)" << endl;
}

// 在析构函数中回收对象指针指向的内存资源
Line::~Line()
{
    cout << "~Line()" << endl;
}


void Line::printInfo()
{
    cout << "(" << m_coorA.getX() << ", " << m_coorA.getY()<<")" << endl;
    cout << "(" << m_coorB.getX() << ", " << m_coorB.getY()<<")" << endl;
}
void Line::printInfo() const
{
    cout << "Line::printInfo() const" << endl;
    cout << "(" << m_coorA.getX() << ", " << m_coorA.getY()<<")" << endl;
    cout << "(" << m_coorB.getX() << ", " << m_coorB.getY()<<")" << endl;
}