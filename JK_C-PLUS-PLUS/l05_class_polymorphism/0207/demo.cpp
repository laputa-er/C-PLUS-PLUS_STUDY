#include <iostream>
using namespace std;

// 形状
class Shape
{
public:
	Shape()
	{
		cout << "Shape()" << endl;
	}
	// 虚析构函数
	virtual ~Shape()
	{
		cout << "virtual ~Shape()" << endl;
	}
	// 虚函数
	virtual double caleArea()
	{
		return 0;
	}
protected:
	int m_iEdge;
};

// 圆
class Circle:public Shape
{
public:
	Circle(double r)
	{
		m_dR = r;
	}
private:
	double m_dR;
};

int main(void)
{
	Shape *shape = new Circle(10.0);
	delete shape;
	shape = NULL;
	return 0;
}