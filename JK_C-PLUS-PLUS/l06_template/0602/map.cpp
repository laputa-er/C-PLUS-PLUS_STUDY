#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	// 使用vector存储数字：3、4、8、4
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(4);

	//循环打印数字
	for(int k = 0; k < vec.size(); k++)
	{
		cout << vec[k] << endl;
	}

	// 使用map来存储字符串键值对
	map<string, string> m;
	pair<string, string> p1("a", "S-Shang Hai");
	pair<string, string> p2("b", "B-Bei Jing");
	pair<string, string> p3("c", "G-Guang Zhou");

	m.insert(p1);
	m.insert(p2);
	m.insert(p3);

	map<string, string>::iterator itor = m.begin();
	for(itor = m.begin(); itor != m.end(); itor++)
	{
		cout << itor->first << endl;
		cout << itor->second << endl;
	}

	return 0;
}