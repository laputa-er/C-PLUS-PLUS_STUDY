#include <iostream>
#include "List.h"
#include "Node.h"

int main(void)
{
	// 创建链表
	List *pList = new List();

	// 初始化需要的节点
	Node node1("Neo", "123456"), node2("Cassiel", "123456"), node3("Ulrica", "123456"), node4("Quella", "123456"), node5("Cecilia", "123456"), node6("Claudia", "123456");

	// 插入节点
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	pList->ListInsertHead(&node6);

	// 遍历
	pList->ListTraverse();

	// 根据第1个数据获取节点
	Node temp;
	pList->GetElem(1, &temp);
	cout << "GetElem: " << temp.data << endl;
	
	return 0;
}