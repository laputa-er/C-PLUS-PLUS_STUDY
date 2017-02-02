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
}
CMap::~CMap()
{
	delete []m_pNodeArray;
	delete []m_pMatrix;
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