#include <iostream>
using namespace std;

// 人
class Person
{
public:
	Person(string name = "Jim")
	{
		m_strName = name;
		cout << "Person()" << endl;
	}
	// 虚析构函数
	virtual ~Person()
	{
		cout << "virtual ~Person()" << endl;
	}
	void play()
	{
		cout << "Person::play" << endl;
	}
protected:
	string m_strName;
};

// 士兵
class Soldier:public Person
{
public:
	Soldier(string name = "James", int age = 20)
	{
		m_strName = name;
		m_iAge = age;
		cout << "Solider()" << endl;
	}
	virtual ~Soldier()
	{
		cout << "virtual ~Solider()" << endl;
	}
	void play()
	{
		cout << "Soldier::play" << endl;
	}
	void work()
	{
		cout << "Soldier::work" << endl;
	}
protected:
	int m_iAge;
};

// 传入拷贝
void func1(Person p)
{
	p.play();
	// 该函数结束时会释放拷贝的实例，出发一次內粗怒回收
}

// 传入指针
void func2(Person *p)
{
	p->play();
}

// 传入引用
void func3(Person &p)
{
	p.play();
}

int main(void)
{
	Soldier s1;
	Soldier *s2 = new Soldier("Neo", 30);

	Person p1 = s1;
	Person *p2 = s2; // s1 是在栈中初始化的，不能检验销毁实例对虚函数的调用情况，因此使用了 s2
	Person &p3 = s1;

    /*
	* 同名成员，访问到的是父类的
	*/
	p1.play(); // Person::play
	p2->play(); // Person::play
	p3.play(); // Person::play

    /*
	* 子类独有的成员，不能访问
	*/
	// p1.work();
	// p2->work();
	// p3.work();

    /*
	* 调用虚析构函数
	*/
	delete p2; // 只执行父类的析构函数
	p2 = NULL;

	/*
	* 作为参数传入(没啥特别的)
	*/
	func1(p1);
	func2(p2);
	func3(p3);
	
	return 0;
}