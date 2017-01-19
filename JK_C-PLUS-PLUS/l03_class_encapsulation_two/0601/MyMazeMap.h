/*
* MazeMap 的代理类，封装 MazeMap 类
* 提供迷宫地图操作的相关类
*/

#ifndef MyMazeMap_H_
#define MyMazeMap_H_

class MazeMap; // 声明下要被代理的类
class MyMazeMap
{
public:
	MyMazeMap();
	/*
	* 使用自定义的地图
	* param{int *} mazeMap 地图二维数组首地址
	* param{int} row 地图行数
	* param{int} column 地图列数
	*/
	MyMazeMap(int *mazeMap, int row, int column);
	~MyMazeMap();
	void setMazeWall(char wall);
	void setMazeRoad(char road);
	void defaultMode();
	void setMazeMap(int *mazeMap, int row, int column); // 重置迷宫地图
	void drawMap() const; // 绘制地图
private:
	MazeMap *mazeMap; // 被代理类型的指针
}

#endif // MyMazeMap_H_