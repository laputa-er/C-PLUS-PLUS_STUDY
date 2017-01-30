#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List
{
public:
List();
~List();
void ClearList(); // 清空数据
bool ListEmpty(); // 判空
int ListLength(); // 获取链表长度
bool GetElem(int i, Node *pNode); // 获取指定下标元素
int LocateElem(Node *pNode); // 获取指定元素的下标
bool PrevElem(Node *pCurrentNode, Node *pPreNode); // 获取前驱
bool NextElem(Node *pCurrentNode, Node *pNextNode);// 获取后继
void ListTraverse(); // 遍历
bool ListInsert(int i, Node *pNode); // 插入元素
bool ListDelete(int i, Node *pNode); // 删除元素
bool ListInsertHead(Node *pNode); // 从头部插入
bool ListInsertTail(Node *pNode); // 从尾部插入
private:
	Node *m_pList;
	int m_iLength;
};

#endif