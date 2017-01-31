#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(int index = 0, int data = 0);
	Node *SearchNode(int nodeIndex); // 递归寻找节点
	void DeleteNode(); // 递归删除节点
	void PreorderTraversal(); // 后序
	void InorderTraversal(); // 中序
	void PostorderTraversal(); // 后序
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};

#endif