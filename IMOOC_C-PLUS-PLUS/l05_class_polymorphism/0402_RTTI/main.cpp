#include <iostream>
#include "Bird.h"
#include "Plane.h"
using namespace std;

// RTTI
void doSomething(Flyable *obj)
{
	cout << typeid(*obj).name() << endl;
	obj->takeOff();
	// 如果对象是 Bird 类
	if(typeid(*obj) == typeid(Bird))
	{
		// 将对象转换为 Bird 类
		Bird *bird = dynamic_cast<Bird *>(obj);
		bird->foraging();
	}
	// 如果对象是 Plane 类
	if(typeid(*obj) == typeid(Plane))
	{	// 将类型转换为 Plane 类
		Plane *plane = dynamic_cast<Plane *>(obj);
		plane->carry();
	}
	obj->land();
}

int main(void)
{
	Bird b;
	doSomething(&b);

	// typeid 基本用法
	Flyable *p = new Bird();

	cout << typeid(int).name() << endl;// i(int)
	cout << typeid(Bird).name() << endl;// 4Bird
	cout << typeid(p).name() << endl; // P7Flyable
	cout << typeid(*p).name() << endl; // 4Bird

	return 0;
}