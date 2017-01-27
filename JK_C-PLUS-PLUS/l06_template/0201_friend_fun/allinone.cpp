#include <iostream>
using namespace std;

class Coordinate;
class Circle
{
public:
	void printXY(Coordinate &c);
};

class Coordinate
{
	// 声明成员友元函数
	friend void Circle::printXY(Coordinate &c);
public:
	Coordinate(int x, int y){}
private:
	int m_iX;
	int m_iY;
};

void Circle::printXY(Coordinate &c)
{
	cout << "Circle -- printXY" << endl;
}

int main(void)
{
	Coordinate coor(5, 6);
    Circle circle;
	circle.printXY(coor);
	return 0;
}
