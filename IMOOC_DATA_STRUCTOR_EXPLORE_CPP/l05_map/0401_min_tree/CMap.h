#ifndef CMAP_H 
#define CMAP_H
#include <vector>
#include "Node.h"
#include "Edge.h"
using namespace std;
class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);
	void resetNode(); // 重置顶点
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1); // 为有向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1); // 为无向图设置邻接矩阵
	void printMatrix(); // 打印邻接矩阵
	void depthFirstTraverse(int nodeIndex); // 深度优先遍历
	void breadthFirstTraverse(int nodeIndex); // 广度优先遍历
	void primTree(int nodeIndex); // 通过普里姆算生成最小生成树
private:
	int getMinEdge(vector<Edge> edgeVec); // 获取边集合中还没被选择的权值最小的边
	bool getValueFromMatrix(int row, int col, int &val); // 从矩阵中获取权值
	void breadthFirstTraverseImpl(vector<int> preVec); // 广度优先遍历实现函数
private:
	int m_iCapacity; // 图中最多容纳的顶点数
	int m_iNodeCount; // 已经添加的顶点（节点）的个数
	Node *m_pNodeArray; // 用来存放顶点数组
	int *m_pMatrix; // 用来存放邻接矩阵
	Edge *m_pEdge; // 已选边集合
};

#endif