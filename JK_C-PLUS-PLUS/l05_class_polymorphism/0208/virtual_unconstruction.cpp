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
	// 定义为虚函数(实现多态)
	virtual double caleArea()
	{
		cout << "virtual double caleArea()" << endl;
		return 0;
	}
};

// 圆
class Circle:public Shape
{
public:
	Circle(int r):m_iR(r)
	{
		cout << "Circle(int r)" << endl;
	}
	virtual ~Circle()
	{
		cout << "virtual ~Circle()" << endl;
	}
private:
	int m_iR;
};

int main(void)
{
	// 虚函数表指针(8)
	Shape shape;
	cout << sizeof(shape) << endl;

	// 虚函数表指针(8) + 数据成员(8)
	Circle circle(100);
	cout << sizeof(circle) << endl;
	
	// shape 对象地址（用整数方式显示地址信息）
	int *p = (int *)&shape;
	cout << p << endl;
	
	// circle 对象地址
	int *q = (int *)&circle;
	cout << q << endl;

	// shape 对象首地址存储的数据(虚函数表地址)
	cout << (unsigned int)(*p) << endl;

	// circle 对象首地址存储的数据(虚函数表地址)
	cout << (unsigned int)(*q) << endl;

	return 0;
}