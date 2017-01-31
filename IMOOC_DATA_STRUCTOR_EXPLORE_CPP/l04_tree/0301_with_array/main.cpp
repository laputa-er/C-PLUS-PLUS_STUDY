#include <iostream>
#include "Tree.h"
using namespace std;

int main(void)
{
	// 创建（构造器要设置好根节点）
	int root = 3;
	Tree *pTree = new Tree(10, &root);

	// 插入节点
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;
	int node5 = 0;
	int node6 = 7;

	pTree->AddNode(0, 0, &node1);
	pTree->AddNode(0, 1, &node2);
	pTree->AddNode(1, 0, &node3);
	pTree->AddNode(1, 1, &node4);
	pTree->AddNode(2, 0, &node5);
	pTree->AddNode(2, 1, &node6);

	// 遍历
	pTree->TreeTraverse();

	// 搜索
	int *p = pTree->SearchNode(2);
	cout << "SearchNode:" << *p << endl;

	// 删除
	int node = 0;
	bool isDeleteSuccess = pTree->DeleteNode(0, &node);
	cout << (isDeleteSuccess ? "true" : "false") << endl;
	pTree->TreeTraverse();

	return 0;
}