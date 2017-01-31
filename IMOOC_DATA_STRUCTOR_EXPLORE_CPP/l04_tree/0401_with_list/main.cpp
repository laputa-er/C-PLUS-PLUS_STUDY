#include <iostream>
#include "Tree.h"
using namespace std;


int main(void)
{
	/*
	* 创建二叉树
	*				0(0)
	*
	*		5(1)			8(2)
	*
	*	2(3)	6(4)	7(5)	9(6)
	*/
	Tree *tree = new Tree();

	Node *node1 = new Node(1, 5);
	Node *node2 = new Node(2, 8);
	Node *node3 = new Node(3, 2);
	Node *node4 = new Node(4, 6);
	Node *node5 = new Node(5, 7);
	Node *node6 = new Node(6, 9);

	tree->AddNode(0, 0, node1);
	tree->AddNode(0, 1, node2);
	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);
	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);

	// 前序
	tree->PreorderTraversal(); // (0) 5(1) 2(3) 6(4) 8(2) 7(5) 9(6)
	// 中序
	tree->InorderTraversal(); // 2(3) 5(1) 6(4) 0(0) 7(5) 8(2) 9(6)
	// 后序
	tree->PostorderTraversal(); // 2(3) 6(4) 5(1) 7(5) 9(6) 8(2) 0(0)

	// 删除节点
	tree->DeleteNode(2, NULL);
	tree->PreorderTraversal();
	
	delete tree;
	tree = NULL;
	return 0;
}