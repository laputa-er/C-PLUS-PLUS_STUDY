/*
* MazePerson 的代理类，创建并设置迷宫中的人
*/
#include "Public.h"

#ifndef MyMazePerson_H_
#define MyMazePerson_H_

class MazePerson;

class MyMazePerson
{
public:
	MyMazePerson();
	MyMazePerson(int currentX, int currentY);
	MyMazePerson(int currentX, int currentY, objectiveDirections myForward);
	~MyMazePerson();
	MyMazePerson &setPersonPosition(int coordinateX, int coordinateY);
	MyMazePerson &setPersonChar(char personChar);
	MyMazePerson &setPersonForward(objectiveDirections myForward);
	void setPersonPos(int coordX, int coordY);
	void setPersonPic(char personChar);
	void setPersonForwardDirection(objectiveDirections myForward);
	void setPersonSpeed(long speed);
	void setPersonSpeed(int speed);
	void start();
private:
	MazePerson *mazePerson;
};

#endif // MyMazePerson_H_