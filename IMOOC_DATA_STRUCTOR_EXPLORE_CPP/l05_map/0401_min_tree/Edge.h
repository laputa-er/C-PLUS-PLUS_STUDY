#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
	int m_iNodeIndexA; // 端点 A 的顶点下标
	int m_iNodeIndexB; // 端点 B 的顶点下标
	int m_iWeightValue; // 权值
	bool m_bSelected; // 是否已经被选择
};
#endif
