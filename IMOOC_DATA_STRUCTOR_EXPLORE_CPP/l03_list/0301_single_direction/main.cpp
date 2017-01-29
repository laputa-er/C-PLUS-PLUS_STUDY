#include <iostream>
#include "List.h"
#include "Node.h"

int main(void)
{
	// 创建链表
	List *pList = new List();

	// 初始化需要的节点
	Node node1, node2, node3, node4, node5, node6;
	node1.data = 3;
	node2.data = 4;
	node3.data = 5;
	node4.data = 6;
	node5.data = 7;
	node6.data = 8;

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