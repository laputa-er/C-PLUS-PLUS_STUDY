/*
* 全局常量
*/

#ifndef Public_H_
#define Public_H_

const int FAST = 1; // 快速
const int MIDD = 2; // 中速
const int SLOW = 3; // 慢速

const int WALL = 1; // 墙壁
const int ROAD = 0; // 通道

enum objectiveDirections
{
	NORTH, // 上
	SOUTH, // 下
	WEST, // 左
	EAST // 右
};

#endif // Public_H_
