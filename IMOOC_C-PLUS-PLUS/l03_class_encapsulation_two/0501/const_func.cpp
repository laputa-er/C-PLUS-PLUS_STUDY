#include <iostream>
using namespace std;

class Coordinate
{
public:
	Coordinate(int x, int y);
	// 常成员函数(只能通过常对象调用)
	void changeX() const;
	void changeX();
private:
	int m_iX;
	int m_iY;
};

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::changeX() const
{
	// m_iX = 10;(会报错)
	cout << "changeX()" << endl;
}
void Coordinate::changeX()
{
	m_iX = 20;
}

int main(void)
{
	// 常对象
	const Coordinate coor(3, 5);
	// 通过常对象才能调用常成员函数
	coor.changeX();
	
	return 0;
}