#include <iostream>
using namespace std;

// 人类
class Person
{
public:
	Person()
	{
		m_strName = "Merry";
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
	void play()
	{
		cout << "Person::play()" << endl;
		cout << m_strName << endl;
	}
protected:
	string m_strName;
};

// 士兵类
class Soldier : public Person
{
public:
	Soldier()
	{
		cout << "Soldier()" << endl;
	}
	~Soldier()
	{
		cout << "~Soldier()" << endl;
	}
	void work()
	{
		cout << "Soldier::work()" << endl;
	}
	void play()
	{
		cout << "Soldier::work" << endl;
	}
};

// 步兵类
class Infantry
{
public:
	Infantry(string name, int age)
	{
		m_strName = name;
		m_iAge = age;
		cout << "Infantry()" << endl;
	}
	~Infantry()
	{

	}
	void Infantry::attack()
	{
		cout << m_strName << endl;
		cout << m_iAge << endl;
		cout << "Infantry::attack()" << endl;
	}
};

int main(void)
{
	Infantry infantry;
	
	return 0;
}