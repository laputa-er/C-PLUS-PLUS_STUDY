/*
* 迷宫中的人的类
*/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Public.h"

using namespace std;

#ifndef MazePerson_H_
#define MazePerson_H_

const bool YES = true;
const bool NO = false;

class MazePerson
{
public:
    MazePerson(); // 构造函数（默认）
    MazePerson(int currentX, int currentY); // 构造函数（位置）
    MazePerson(int currentX, int currentY, objectiveDirections myForward); // 构造函数（位置和方向）
    MazePerson &setPersonPosition(char personChar); // 设置人的位置
    MazePerson &setPersonChar(char personChar); // 设置代表人的字符
    MazePerson &setPersonForward(objectiveDirections myForward); // 设定人的方向
    void setPersonPos(int coordX, int coordY); // 设定人的位置
    void setPersonPic(char personChar); // 设定人的表示字符
    void setPersonForwardDirection(objectiveDirections myForward); // 设置人的方向
    void setPersonSpeed(long speed); // 设定人的速度
    void setPersonSpeed(int speed); // 设置人的速度
    void start(); // 开始运动

private:
    int preX; // 前一个位置的横坐标
    int preY; // 前一个位置的纵坐标
    int positionX; // 当前位置的横坐标
    int pisitionY; // 当前位置的纵坐标
    int personSpeed; // 人当前的移动速度
    char personPic; // 表示人的字符
    bool outOrNo; // 是否走出了迷宫
    objectiveDirections forward; // 方向

    void savePrePosition(); // 保存前一个坐标位置
    void moveSouth(); // 向南走
    void moveNorth(); // 向北走
    void moveWest(); // 向西走
    void moveEast(); // 向东走
    void turnLeft(); // 向左转
    void turnRight(); // 向右转
    void goAhead(); // 向当前防线前进
    bool moveForward(); // 可以进行主观判断如何前进的方法
    void gotoxy(int x, int y); // 设定输出位置
    void drawPerson(); // 绘制人的行走动画
};
#endif // MazePerson_H_