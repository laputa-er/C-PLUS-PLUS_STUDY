/*
* 定义 MazeMap 类: 声明并绘制地图
*/

#include "Public.h"

#ifndef MAZEMAP_H_

#define screenWidth 80 // 地图宽度(字符)
#define screenHeight 25 // 地图宽度(字符)

class MazeMap
{
public:
	MazeMap(); // 默认地图
	MazeMap(int *mazeMap, int row, int colum); // 自定义地图
	void setMazeWall(char wall); // 设置墙
	void setMazeRoad(char road); // 设置通道
	void defaultMode(); // 指定使用默认地图
	void setMazeMap(int *mazeMap, int row, int colum); // 重置地图
	void drawMap() const; // 绘制地图
	static char getRoadChar(); // 获取表示通道的字符
	static bool checkWallOrNot(int mazeX, int mazeY); // 检查指定坐标初是否是墙
	static bool checkMazeDoor(int mazeX, int mazeY); // 检查指定坐标是否是入口（出口）
private:
	char mazeWall; // 墙字符
	static char mazeRoad;  // 通路字符
	static int mazeWidth; // 迷宫宽度
	static int mazeHeight; // 迷宫高度
	static int mazeMapArray[screenHeight][screenWidth]; // 地图二维数组
};

#endif // MAZEMAP_H_
