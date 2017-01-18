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
    MazePerson(); // 默认构造器
    MazePerson(int currentX, int currentY); // 
    MazePerson(int currentX, int currentY, objectiveDirections myForward);
    MazePerson &setPersonPosition(int char personChar);    
};
#endif // MazePerson_H_