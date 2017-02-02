#include <iostream>
#include "CMap.h"
using namespace std;

int main(void)
{
	/*
	* 图的存储与遍历
	*
	* 1. 无向图
	* 2. 采用邻接矩阵（权值都为1）
	*
	*		 A
	*	   /   \
	*	  B      D
	*    / \    /  \
	*	C   F  G  - H
	*   \   /
	*     E
    *
	*      A B C D E F G H
	*
	*  A   0 1 0 1 0 0 0 0
	*  B   1 0 1 0 0 1 0 0
	*  C   0 1 0 0 1 0 0 0
	*  D   1 0 0 0 0 0 1 1
	*  E   0 0 1 0 0 1 0 0 
	*  F   0 1 0 0 1 0 0 0 
	*  G   0 0 0 1 0 0 0 1
	*  H   0 0 0 1 0 0 1 0
	*
	*/
	// 创建图
	CMap *pMap = new CMap(8);

	// 创建顶点顶点
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');

	// 添加顶点
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	// 设置邻接矩阵（无向图）
	pMap->setValueToMatrixForUndirectedGraph(0, 1);
	pMap->setValueToMatrixForUndirectedGraph(0, 3);
	pMap->setValueToMatrixForUndirectedGraph(1, 2);
	pMap->setValueToMatrixForUndirectedGraph(1, 5);
	pMap->setValueToMatrixForUndirectedGraph(3, 6);
	pMap->setValueToMatrixForUndirectedGraph(3, 7);
	pMap->setValueToMatrixForUndirectedGraph(6, 7);
	pMap->setValueToMatrixForUndirectedGraph(2, 4);
	pMap->setValueToMatrixForUndirectedGraph(4, 5);

	// 打印邻接矩阵
	pMap->printMatrix();
	cout << endl;

	pMap->resetNode();

	// 深度遍历
	pMap->depthFirstTraverse(0); // A B C E F D G H
	cout << endl;

	pMap->resetNode();

	// 广度遍历
	pMap->breadthFirstTraverse(0); // A B D C F G H E
	cout << endl;
	return 0;
}