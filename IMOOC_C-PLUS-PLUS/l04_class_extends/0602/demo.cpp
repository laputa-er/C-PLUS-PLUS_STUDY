#include <iostream>
#include <string.h>
using namespace std;

// 人
class Person
{
public:
	Person(string color = "blue")
	{
		m_strColor = color;
		cout << "Person()" << endl;
	}
	// 虚析构函数
	virtual ~Person()
	{
		cout << "virtual ~Person()" << endl;
	}
	void printColor()
	{
		cout << m_strColor << endl;
		cout << "Person::printColor()" << endl;
	}
protected:
	string m_strColor;
};

// 农民
class Farmer:virtual public Person
{
public:
	Farmer(string name = "Jack", string color = "green"):Person("Farmer" + color)
	{
		cout << "Farmer()" << endl;
	}
	virtual ~Farmer()
	{
		cout << "virtual ~Farmer()" << endl;
	}
protected:
	string m_strName;
};

// 工人
class Worker:virtual public Person
{
public:
	Worker(string code = "001", string color = "blue"):Person("Worker" + color)
	{
		m_strCode = code;
		cout << "Worker()" << endl;
	}
	virtual ~Worker()
	{
		cout << "virtual ~Worker()" << endl;
	}
	void carry()
	{
		cout << m_strCode << endl;
		cout << "Worker::carry()" << endl;
	}
protected:
	string m_strCode;
};

// 农民工
class MigrantWorker:public Farmer, public Worker
{
public:
	// 在初始化类表中调用父类的构造器完成实例中父类部分的初始化
	MigrantWorker(string name, string code, string color):Farmer(name, color), Worker(code, color)
	{
		cout << "MigrantWorker()" << endl;
	}
	~MigrantWorker()
	{
		cout << "~MigrantWorker()" << endl;
	}
};

int main(void)
{
	MigrantWorker *mw = new MigrantWorker("xiaohai", "12345", "blue");
	mw->Worker::printColor();
	mw->Farmer::printColor();

	delete mw;
	mw = NULL;
	return 0;
}