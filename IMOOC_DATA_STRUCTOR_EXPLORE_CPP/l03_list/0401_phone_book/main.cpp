#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

// 功能提示、接收用户的指令
int menu()
{
	// 显示通讯录功能菜单
	cout << "功能菜单" << endl;
	cout << "1. 新建联系人" << endl;
	cout << "2. 删除联系人" << endl;
	cout << "3. 浏览通讯录" << endl;
	cout << "4. 退出通讯录" << endl;

	cout << "请输入：";
	int order = 0;
	cin >> order;
	return order;
}

// 创建联系人
void createPerson(List *pList)
{
	Person person;
	Node node;
	cout << "请输入姓名：";
	cin >> person.name;
	cout << "请输入电话：";
	cin >> person.phone;
	node.data = person;
	pList->ListInsertTail(&node); // 事实上并没有真的把这个 node 插入了链表，而是将 node 的 data 数据赋值给了载堆中新创建的节点
}

// 删除联系人
void deletePerson(List *pList)
{
	Node node;
	Person person;
	cout << "请输入要删除的联系人的姓名:";
	cin >> person.name;
	cout << "请输入要删除的联系人的电话:";
	cin >> person.phone;
	node.data = person;
	int index = pList->LocateElem(&node);
	cout << "index:" << index << endl;
	if(pList->ListDelete(index, &node))
	{
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "没有找到!" << endl;
	}
}

int main(void)
{	
	int userOrder = 0;
	List *pList = new List();
	while(userOrder != 4)
	{
		userOrder = menu();
		switch(userOrder)
		{
			case 1:
				cout << "用户指令--->>新建联系人：" << endl;
				createPerson(pList);
				break;
			case 2:
				cout << "用户指令--->>删除联系人：" << endl;
				deletePerson(pList);
				break;
			case 3:
				cout << "用户指令--->>浏览通讯录：" << endl;
				pList->ListTraverse();
				break;
			case 4:
				cout << "用户指令--->>退出通讯录：" << endl;
				break;
			default:
				cout << "非法指令！" << endl;
				break;
		}
	}

	delete pList;
	pList = NULL;
	return 0;
}