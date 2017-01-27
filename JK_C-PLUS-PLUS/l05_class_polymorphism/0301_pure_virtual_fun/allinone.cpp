#include <iostream>
#include <string.h>
using namespace std;

// 人（抽象类）
class Person
{
public:
	Person(string name):m_strName(name)
	{
		cout << "Person(string name)" << endl;
	}
	virtual ~Person()
	{
		cout << "virtual ~Person()" << endl;
	}
	virtual void work() = 0;
private:
	string m_strName;
};

// 工人（抽象类）
class Worker:public Person
{
public:
	Worker(string name):Person(name)
	{
		cout << "Worker(string name)" << endl;
	}
	virtual ~Worker()
	{
		cout << "virtual ~Worker()" << endl;
	}
};

// 清洁工
class Dustman:public Worker
{
public:
	Dustman(string name, int age):Worker(name), m_iAge(age)
	{
		cout << "Dustman()" << endl;
	}
	virtual ~Dustman()
	{
		cout << "virtual ~Dustman()" << endl;
	}
	virtual void work()
	{
		cout << "扫地" << endl;
	}
private:
	int m_iAge;
};

int main(void)
{
	Dustman dustman = Dustman("Doris", 45);
	dustman.work();
	
	return 0;
}