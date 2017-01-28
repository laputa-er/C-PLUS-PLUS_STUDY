/*
* 实现代理类 MyMazeMap
*/
#include "MazeMap.h"
#include "MyMazeMap.h"

MyMazeMap::MyMazeMap()
{
	mazeMap = new MazeMap;
}

MyMazeMap::MyMazeMap(int *mazeMap, int row, int column)
{
	this->mazeMap = new MazeMap(mazeMap, row, column);
}

void MyMazeMap::defaultMode()
{
	this->mazeMap->defaultMode();
}

void MyMazeMap::drawMap() const
{
	mazeMap->drawMap();
}

void MyMazeMap::setMazeMap(int *mazeMap, int row, int column)
{
	this->mazeMap->setMazeMap(mazeMap, row, column);
}

void MyMazeMap::setMazeRoad(char road)
{
	mazeMap->setMazeRoad(road);
}

void MyMazeMap::setMazeWall(char wall)
{
	mazeMap->setMazeWall(wall);
}

MyMazeMap::~MyMazeMap()
{
	delete mazeMap;
}