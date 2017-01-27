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
	~Shape()
	{
		cout << "~Shape()" << endl;
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
	Circle(double r)
	{
		cout << "Circle(double r)" << endl;
		m_dR = r;
	}
	// 定位为虚析构函数，保证通过父类指针能调用子类的虚构函数
	virtual ~Circle()
	{
		cout << "virtual ~Circle()" << endl;
	}
	// 由于父类同名函数已经使用了 virtual 修饰，这里的 virtual 计算机会自动添加，因此可以参略，
	virtual double calcArea() {
		cout << "Circle::calcArea()" << endl;
		return 3.14 * m_dR * m_dR;
	}
private:
	double m_dR;
};

// 矩形
class Rect:public Shape
{
public:
	Rect(double width, double height)
	{
		cout << "Rect(double width, double height)" << endl;
		m_dWidth = width;
		m_dHeight = height;
	}
	virtual ~Rect()
	{
		cout << "virtual ~Rect()" << endl;
	}
	virtual double calcArea()
	{
		cout << "Rect::calcArea()" << endl;
		return m_dWidth * m_dHeight;
	}
private:
	double m_dWidth;
	double m_dHeight;
};

int main(void)
{
	// 父类型指针指向子类实例
	Shape *shape1 = new Circle(4.0);
	Shape *shape2 = new Rect(3.0, 5.0);

	// 调用的是子类定义的函数
	shape1->calcArea();
	shape2->calcArea();

	delete shape1;
	delete shape2;

	shape1 = NULL;
	shape2 = NULL;
	return 0;
}