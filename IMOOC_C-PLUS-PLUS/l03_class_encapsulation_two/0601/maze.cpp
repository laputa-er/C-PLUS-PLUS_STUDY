#include <iostream>
#include <stdlib.h>
#include "MyMazeMap.h"
#include "MyMazePerson.h"

using namespace std;

const int SUCCESS = 0;

int main(void)
{
	int map[8][9] = {
		{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
		{WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
		{WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
		{WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
		{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	};
	MyMazeMap maze;
	maze.setMazeMap(&map[0][0], 8, 9);
	maze.setMazeWall('*');
	maze.drawMap();
	MyMazePerson mazePerson;
	mazePerson.setPersonPosition(1, 7);
	mazePerson.setPersonSpeed(FAST);
	mazePerson.setPersonChar('T');
	mazePerson.start();

	system("pause");

	return SUCCESS;
}