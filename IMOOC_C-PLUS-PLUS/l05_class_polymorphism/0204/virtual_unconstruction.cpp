#include <iostream>

using namespace std;
// 坐标
class Coordinate
{
public:
	Coordinate(int x, int y):m_iX(x), m_iY(y)
	{
		cout << "Coordinate()" << endl;
	}
	~Coordinate()
	{
		cout << "~Coordinate()" << endl;
	}
private:
	int m_iX;
	int m_iY;
};

// 形状
class Shape
{
public:
	Shape()
	{
		cout << "Shape()" << endl;
	}
	virtual ~Shape()
	{
		cout << "virtual ~Shape()" << endl;
	}

	// 父类中该方法定义为虚函数
	virtual double calcArea()
	{
		cout << "calcArea" << endl;
		return 0;
	}
};

// 圆形
class Circle:public Shape
{
public:
	Circle(int x, int y, double r)
	{
		cout << "Circle(double r)" << endl;
		m_pCenter = new Coordinate(x, y);
		m_dR = r;
	}

	virtual ~Circle()
	{
		delete m_pCenter;
		m_pCenter = NULL;
		cout << "virtual ~Circle()" << endl;
	}
	// 由于父类同名函数已经使用了 virtual 修饰，这里的 virtual 计算机会自动添加，因此可以参略，
	virtual double calcArea() {
		cout << "Circle::calcArea()" << endl;
		return 3.14 * m_dR * m_dR;
	}
private:
	double m_dR;
	Coordinate *m_pCenter;
};

int main(void)
{
	// 父类型指针指向子类实例
	Shape *shape1 = new Circle(0, 5, 3.5);

	// 调用的是子类定义的函数
	shape1->calcArea();

	delete shape1;

	shape1 = NULL;
	return 0;
}