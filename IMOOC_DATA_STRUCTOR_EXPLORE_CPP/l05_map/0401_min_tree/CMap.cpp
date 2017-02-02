#include <iostream>
#include "CMap.h"
#include <vector>

using namespace std;

CMap::CMap(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0; // 已经设置的当前顶点数量
	m_pNodeArray = new Node[m_iCapacity]; // 为顶点数组分配内存
	m_pMatrix = new int[m_iCapacity * m_iCapacity]; // 为邻接矩阵分配内存
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int)); // 初始化邻接矩阵每个元素的值为0

	m_pEdge = new Edge[m_iCapacity - 1]; // 最小生成树的边的数量为顶点的数量-1
}
CMap::~CMap()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
	delete []m_pEdge;
	m_pNodeArray = NULL;
	m_pMatrix = NULL;
}

bool CMap::addNode(Node *pNode)
{
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void CMap::resetNode()
{
	for(int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

void CMap::printMatrix()
{
	for(int i = 0; i < m_iCapacity; i++)
	{
		for(int k = 0; k < m_iCapacity; k++)
		{
			cout << m_pMatrix[i * m_iCapacity + k] << " ";
		}
		cout << endl;
	}
}

bool CMap::getValueFromMatrix(int row, int col, int &val)
{
	if(row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if(col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

/*
* 深度优先遍历
* 遍历一遍所有节点，并把遍历过的节点的 m_bIsvisited 属性设置为 true
* @param{int} nodeIndex 遍历的起点
*/
void CMap::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	// 从邻接矩阵中寻找和当前节点存在连接的节点
	for(int i = 0; i < m_iCapacity; i++)
	{
		// 读取邻接矩阵中的值
		getValueFromMatrix(nodeIndex, i, value);
		// 存在连线, 也就意味着找到了一个节点，其下标为 i
		if(value != 0)
		{
			if(m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else
		{
			continue;
		}
	}
}

/*
* 广度优先遍历
*/
void CMap::breadthFirstTraverse(int nodeIndex)
{
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	vector<int> curVec;
	curVec.push_back(nodeIndex);
	// 依次遍历当前 curVec 中的节点所有的子节点
	breadthFirstTraverseImpl(curVec);
}

/*
* 依次遍历指定节点下标集合中所有节点的字节点
*/
void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	int value = 0;
	// 声明下一层节点下标集合
	vector<int> curVec;

	// 遍历上一层节点下标集合
	for(int j = 0; j < (int)preVec.size(); j++)
	{
		// 通过邻接矩阵寻找邻接点
		for(int i = 0; i < m_iCapacity; i++)
		{
			// 获取邻接矩阵中的值
			getValueFromMatrix(preVec[j], i, value);
			if(value != 0)
			{
				if(m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;
					curVec.push_back(i);
				}
			}
			else
			{
				continue;
			}
		}
	}
	if(curVec.size() > 0)
	{
		breadthFirstTraverseImpl(curVec);
	}
}

// 普里姆算法生成最小生成树
void CMap::primTree(int nodeIndex)
{
	int value = 0; // 临时存放从临界矩阵中获取的权值
	int edgeCount = 0; // 获得的边的数量
	vector<Edge> edgeVec; // 边的集合
	vector<int> nodeVec; // 下一个要
	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	// 如果顶点的数量为 N ，最小生成树边的数量就是 N -1，以此作为循环的终止条件
	while(edgeCount < m_iCapacity -1)
	{
		int temp = nodeVec.back();
		// 找到所有的备选边
		// 遍历出和下标为 temp 的顶点有连线的点
		for(int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(temp, i, value);

			if(value != 0)
			{
				// 如果下一个点被选择了，就跳过
				if(m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					// 在已选边集合中添加一个新的边
					Edge edge(temp, i, value);
					edgeVec.push_back(edge);
				}
			}
		}
		// 从可选边集合中找出最小的边
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		cout << m_pNodeArray[edgeVec[edgeIndex].m_iNodeIndexA].m_cData << "-" << m_pNodeArray[edgeVec[edgeIndex].m_iNodeIndexB].m_cData << " ";

		// 将这次找到的最小边放入到集合中
		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		edgeCount++;

		// 通过找到的边拿到新发现的点
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true; // 设置,点被选择了
	}
	cout << endl;
}

// 从待选边中找到权值最小的边
int CMap::getMinEdge(vector<Edge> edgeVec)
{
	int minWeight = 0; // 最小边的权值
	int edgeIndex = 0; // 最小边的下标

	// 找到还没选择的边中最小的
	for(int i = 0; i < edgeVec.size(); i++)
	{
		if(!edgeVec[i].m_bSelected)
		{
			if(minWeight == 0)
			{
				minWeight = edgeVec[i].m_iWeightValue;
			}
			else if(minWeight > edgeVec[i].m_iWeightValue)
			{
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
			}
		}
	}
	// 所有的边都已经被选过了，因此没有最小边
	if(minWeight == 0)
	{
		return -1;
	}
	return edgeIndex;
}

void CMap::kruskalTree()
{
	int value = 0;
	int edgeCount = 0;
	// 定义存放节点集合的数组
	vector< vector<int> >nodeSets;

	// 第一步：取出所有的边
	vector<Edge> edgeVec;
	// 只遍历临邻接矩阵上半部分就足够了
	for(int i = 0; i < m_iCapacity; i++)
	{
		for(int k = i + 1; k < m_iCapacity; k++)
		{
			getValueFromMatrix(i, k, value);
			if(value != 0)
			{
				Edge edge(i, k, value);
				edgeVec.push_back(edge);
			}
		}
	}

	// 第二步：从所有边中取出组成最小生成树的边
	// 1. 找到算法的结束条件
	while(edgeCount < m_iCapacity - 1)
	{
		// 2. 从边集合中找到最小边
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;
		
		// 3. 找出最小边连接的点
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

		// 4. 找出点所在的点集合
		bool nodeAIsInSet = false;
		bool nodeBIsInSet = false;
		int nodeAInSetLabel = -1; // A 端所在的点集合下标
		int nodeBInSetLabel = -1; // B 端所在的点集合下标
		// 获取 A 端所在的点集合下标（如果找到的话）
		for(int i = 0; i < nodeSets.size(); i++)
		{
			nodeAIsInSet = isInSet(nodeSets[i], nodeAIndex);
			if(nodeAIsInSet)
			{
				nodeAInSetLabel = i;
			}
		}
		// 获取 B 端所在的点集合下标（如果找到的话）
		for(int i = 0; i < nodeSets.size(); i++)
		{
			nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);
			if(nodeBIsInSet)
			{
				nodeBInSetLabel = i;
			}
		}
		// 5. 根据点所在集合的不同做出不同处理
		// 两个端点都不在已有集合中
		if(nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		}
		// A 不在某个集合中， B 在某个集合中
		else if(nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
		}
		// A 在某个集合中， B 不在某个集合中
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		}
		// A 和 B 分别在两个不同的集合中
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel != nodeBIsInSet)
		{
			// 将 B 所在的集合合并到 A 所在的集合
			mergeNodeSet(nodeSets[nodeAInSetLabel], nodeSets[nodeBInSetLabel]);
			// 把原来的 B 集合清除掉
			for(int k = nodeBInSetLabel; k < (int)nodeSets.size(); k++)
			{
				nodeSets[k] = nodeSets[k + 1];
			}
		}
		// 如果 A、B 本来已经都在同一个集合中了，那么再连线就成了回路，因此要把这条边放弃掉
		else if(nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBIsInSet)
		{
			continue;
		}
		
		// 6. 最后把新确定的一条边添加进最小生成树集合
		m_pEdge[edgeCount] = edgeVec[minEdgeIndex];
		edgeCount++;

		cout << edgeVec[minEdgeIndex].m_iNodeIndexA << "-" << edgeVec[minEdgeIndex].m_iNodeIndexB << " ";
		cout << edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

bool CMap::isInSet(vector<int> nodeSet, int target)
{
	for(int i = 0; i < nodeSet.size(); i++)
	{
		if(nodeSet[i] == target)
		{
			return true;
		}
	}
	return false;
}

void CMap::mergeNodeSet(vector<int> &nodeSetA, vector<int> nodeSetB)
{
	for(int i = 0; i < nodeSetB.size(); i++)	
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}