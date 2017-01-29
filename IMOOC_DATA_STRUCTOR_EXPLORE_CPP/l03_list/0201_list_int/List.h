#ifndef LIST_H
#define LIST_H

class List
{
public:
	List(int size);
	~List();
	void ClearList(); // 清空数据
	bool ListEmpty(); // 判空
	int ListLength(); // 获取链表长度
	bool GetElem(int i, int *e); // 获取指定下标元素
	int LocateElem(int *e); // 获取指定元素的下标
	bool PrevElem(int *currentElem, int *preElem); // 获取前驱
	bool NextElem(int *currentElem, int *nextElem);// 获取后继
	void ListTraverse(); // 遍历
	bool ListInsert(int i, int *e); // 插入元素
	bool ListDelete(int i, int *e); // 删除元素
private:
	int *m_pList;
	int m_iSize;
	int m_iLength;
};

#endif