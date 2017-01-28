#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vec; // 初始化
	vec.push_back(3); // 从尾部插入一个数据
	vec.push_back(5); // 从尾部插入一个数据
	vec.push_back(7); // 从尾部插入一个数据
	vec.pop_back(); // 从尾部删除一个数据
	cout << vec.size() << endl; // 查看数据数量
	
	cout << vec.size() << endl;

	// for 遍历
	for(int k = 0; k < vec.size(); k++)
	{
		cout << vec[k] << endl;
	}

	// 使用迭代器遍历
	vector<int>::iterator citer = vec.begin();
	for(; citer != vec.end(); citer++)
	{
		cout << *citer << endl;
	}

	cout << vec.front() << endl; // 第一个数据
	cout << vec.back() << endl; // 最后一个数据
	return 0;
}