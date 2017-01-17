#include <iostream>
#include "Coordinate.h"
using namespace std;

int main(void)
{
    // 在栈中创建对象实例
    Coordinate coor1(3, 5);
    //1---------------
    // 对象引用
    Coordinate &coor2 = coor1;
    coor2.printInfo(); // (3, 5)

    // 对象指针
    Coordinate *pCoor1 = &coor1;
    pCoor1->printInfo(); // (3, 5)

    //2---------------
    // 对象常引用(只能调用常成员函数)
    const Coordinate &coor3 = coor1;
    coor3.printInfo(); // (3, 5)
    // coor3.getX(); （报错，getX 的 this 需要有读写权限）

    // 常对象指针(智能调用常成员函数)
    const Coordinate *pCoor2 = &coor1;
    pCoor2->printInfo(); // (3, 5)
    // pCoor2.getX(); （报错，getX 的 this 需要有读写权限）

    //3---------------
    Coordinate coor4(3, 9);
    // 对象常指针(对指向的对象仍然有读写权限，但本身地址不可修改)
    Coordinate * const pCoor3 = &coor1;
    pCoor3->getY();
    // pCoor3 = &coor4;(报错，指针本身只读)
    pCoor3->printInfo();
    return 0;
}
