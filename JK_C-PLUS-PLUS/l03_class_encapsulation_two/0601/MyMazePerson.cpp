#include "MyMazePerson.h"
#include "MazePerson.h"

MyMazePerson::MyMazePerson():mazePerson(new MazePerson)
{
	// empty
}

MyMazePerson::MyMazePerson(int currentX, int currentY)
{
	mazePerson = new MazePerson(currentX, currentY);
}

MyMazePerson::MyMazePerson(int currentX, int currentY, objectiveDirections myForward)
{
	mazePerson = new MazePerson(currentX, currentY, myForward);
}

MyMazePerson::~MyMazePerson()
{
	delete mazePerson;
}

void MyMazePerson::setPersonPic(char personChar)
{
	mazePerson->setPersonPic(personChar);
}

MyMazePerson& MyMazePerson::setPersonChar(char personChar)
{
	mazePerson->setPersonChar(personChar);
	return *this;
}

void MyMazePerson::setPersonForwardDirection(objectiveDirections myForward)
{
	mazePerson->setPersonForwardDirection(myForward);
}

MyMazePerson &MyMazePerson::setPersonForward(objectiveDirections myForward)
{
	mazePerson->setPersonForward(myForward);
	return *this;
}

void MyMazePerson::setPersonPos(int coordinateX, int coordinateY)
{
	mazePerson->setPersonPos(coordinateX, coordinateY);
}

MyMazePerson &MyMazePerson::setPersonPosition(int coordinateX, int coordinateY)
{
	mazePerson->setPersonPosition(coordinateX, coordinateY);
	return *this;
}

void MyMazePerson::setPersonSpeed(int speed)
{
	mazePerson->setPersonSpeed(speed);
}

void MyMazePerson::setPersonSpeed(long speed)
{
	mazePerson->setPersonSpeed(speed);
}

void MyMazePerson::start()
{
	mazePerson->start();
}
