#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	list<int> l1;
	l1.push_back(2);
	l1.push_back(4);
	l1.push_back(5);

	// 使用迭代器遍历 list
	list<int>::iterator itor = l1.begin();
	for(; itor != l1.end(); itor++)
	{
		cout << *itor << endl;
	}
	return 0;
}