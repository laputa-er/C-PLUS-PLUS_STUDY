#include <iostream>
using namespace std;
class Coordinate
{
public:
    int m_iX;
    int m_iY;
};

int main(void)
{
    // 在栈中定义
    Coordinate coord[3];
    coord[0].m_iX = 90;
    coord[1].m_iX = 10;
    coord[2].m_iY = 17;
    cout << "(*coord).m_iX" << (*coord).m_iX << endl; // 数组名可以当作指针处理

    // 在堆中定义
    Coordinate *p = new Coordinate[3];
    p[0].m_iY = 7;
    p->m_iY = 9; // p 实际指向数组的第一个元素 p[0]
    Coordinate *q = p; // 为了防止对 p 的操作导致不指向数组第一个元素，声明一个副本
    q++;
    q->m_iY = 17; // p[1]

    for(int i = 0; i < 3; i++)
    {
        cout << "coord:(" << coord[i].m_iX << ", " << coord[i].m_iY << ")"<< endl;
    }
    for (int j = 0; j < 3; j++)
    {
        cout << "p:(" << p[j].m_iX << ", " << p[j].m_iY << ")" << endl;
    }

    delete []p;
    p = q = NULL;
    

    return 0;
}
