#include <iostream>
#include <string.h>
using namespace std;

// 农民
class Farmer
{
public:
	Farmer(string name = "Jack")
	{
		cout << "Farmer()" << endl;
	}
	virtual ~Farmer()
	{
		cout << "virtual ~Farmer()" << endl;
	}
	void show()
	{
		cout << "show()" << endl;
	}
protected:
	string m_strName;
};

// 工人
class Worker
{
public:
	Worker(string code = "001")
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
	MigrantWorker(string name, string code):Farmer(name), Worker(code)
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
	MigrantWorker *mv = new MigrantWorker("Merry", "100");
	mv->carry();
	mv->show();

	delete mv;
	mv = NULL;

	return 0;
}
