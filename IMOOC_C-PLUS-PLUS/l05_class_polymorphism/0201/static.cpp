#include <iostream>
using namespace std;

/*
* 静态多态（函数重载）
*/
class Rect
{
public:
	/*
	* 计算正方形面积
	*/
	int calcArea(int width)
	{
		return width * width;
	}

	/* 
	* 计算一般矩形面积
	*/
	int calcArea(int width, int height)
	{
		return width * height;
	}
};

int main(void)
{
	Rect rect;
	rect.calcArea(10);
	rect.calcArea(10, 20);

	return 0;
}