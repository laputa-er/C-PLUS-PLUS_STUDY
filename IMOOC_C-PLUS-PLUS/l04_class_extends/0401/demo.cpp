#include <iostream>
using namespace std;

// 人
class Person
{
public:
	void play()
	{
		cout << "Person::play" << endl;
	}
protected:
	string m_strName;
	int code;
};

// 士兵
class Soldier:public Person
{
public:
	void play()
	{
		cout << "Soldier::play" << endl;
	}
	void work()
	{
		code = "1234"; // 自身的 code 
		Person::code = 5678; // 父类的 code
		cout << "Soldier::work" << endl;
	}
protected:
	string code;
};

int main(void)
{
	Soldier soldier;

	// 同名函数
	soldier.play(); // 子类的 play (父类的 play 被隐藏)
	soldier.Person::play(); // 调用父类的 play
		
	return 0;
}