#include <iostream>
using namespace std;

/*
* 坦克类
* 每实例化一个坦克对象静态计数器加一
* 每销毁一个坦克对象静态计数器减一
*/
class Tank
{
public:
	Tank(){s_iCount++;}
	~Tank(){s_iCount--;}
	// 静态成员函数
	static int getCount(){return s_iCount;}
	// 静态数据成员
	static int s_iCount;
private:
	string m_strCode;
};

// 初始化静态数据成员的值（不再需要 static 关键字）
int Tank::s_iCount = 0;


int main(void)
{
	// 通过类直接访问
	cout << Tank::getCount() << endl;
	cout << Tank::s_iCount << endl;

	// 通过对象访问
	Tank tank;
	cout << tank.getCount() << endl;
	cout << tank.s_iCount << endl;

	return 0;
}