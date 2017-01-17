/*
* 定义 MazeMap 类: 声明并绘制地图
*/

#include <iostream>
#include "MazeMap.h"

using namespace std;

// 初始化 MazeMap 的 static 变量
char MazeMap::mazeRoad = ' ';
int MazeMap::mazeWidth = 0;
int MazeMap::mazeHeight = 0;
int MazeMap::mazeMapArray[screenHeight][screenWidth];

// 默认构造函数
MazeMap::MazeMap():mazeWall('#')
{
	mazeWidth = 60;
	mazeHeight = 20;
}

// 使用自定义的迷宫
MazeMap::MazeMap(int *mazeMap, int row, int colum):mazeWall('#')
{
	setMazeMap(mazeMap, row, colum);
}

void MazeMap::setMazeMap(int *mazeMap, int row, int column)
{
	mazeHeight = row;
	mazeWidth = column;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			mazeMapArray[i][j] = *mazeMap;
			mazeMap++;
		}
	}
}

void MazeMap::setMazeRoad(char road)
{
	mazeRoad = road;
}

void MazeMap::setMazeWall(char wall)
{
	mazeWall = wall;
}

void MazeMap::defaultMode()
{
	int mazeMap[6][6] = {
		{WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, WALL, WALL, ROAD, ROAD},
		{WALL, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, WALL, WALL, WALL}
	};
	setMazeMap(&mazeMap[0][0], 6, 6);
}

void MazeMap::drawMap() const
{
	for(int i = 0; i < mazeHeight; i++)
	{
		for(int j = 0; j < mazeWidth; j++)
		{
			if(mazeMapArray[i][j] == WALL)
			{
				cout << mazeWall;
			}
			else
			{
				cout << mazeRoad;
			}
		}
	}
}

char MazeMap::getRoadChar()
{
	return mazeRoad;
}

bool MazeMap::checkWallOrNot(int mazeX, int mazeY)
{
	return mazeMapArray[mazeY][mazeX] == WALL;
}

bool MazeMap::checkMazeDoor(int mazeX, int mazeY)
{
	// 确认是否是通道
	if(mazeMapArray[mazeY][mazeX] == ROAD)
	{
		// 确认是否到了迷宫边界
		return (mazeX == 0 || // 左
		   mazeX == (mazeWidth - 1) || //  右
		   mazeY == 0 || // 上
		   mazeY == (mazeHeight - 1)); // 下;
	}
	return false;
}

