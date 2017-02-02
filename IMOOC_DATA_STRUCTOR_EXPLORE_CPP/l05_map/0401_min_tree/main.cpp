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
	* 图示
	*		 A
	*	   / |  \
	*	 B - F - E
	*    \  / \  /
	*	  C  - D
    *
	* 节点
	*  A B C D E F
	*  0 1 2 3 4 5
	*
	* 邻接矩阵
	*      A B C D E F
	*
	*  A   0 6 0 0 5 1
	*  B   6 0 3 0 0 2
	*  C   0 3 0 7 0 8
	*  D   0 0 7 0 2 4
	*  E   5 0 0 2 0 9
	*  F   1 2 8 4 9 0 
	*
	*/
	// 创建图
	CMap *pMap = new CMap(6);

	// 创建顶点顶点
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');

	// 添加顶点
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	// 设置邻接矩阵（无向图）
	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);

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
	cout << endl << endl;
	
	pMap->resetNode();
	
	// 获取最小生成树(普里姆算法)
	pMap->primTree(0); // A-F F-B B-C F-D D-E
	return 0;
}