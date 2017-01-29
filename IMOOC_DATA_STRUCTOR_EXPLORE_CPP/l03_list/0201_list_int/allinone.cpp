#include <iostream>

using namespace std;

// 顺序表
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

int main(void)
{
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;

	List *list1 = new List(10);
	list1->ListInsert(0, &e1);
	list1->ListInsert(0, &e2);
	list1->ListInsert(0, &e3);
	list1->ListInsert(0, &e4);
	list1->ListInsert(0, &e5);
	list1->ListInsert(0, &e6);
	list1->ListInsert(0, &e7);
	
	int temp = 0;
	list1->ListDelete(0, &temp);
	list1->ListTraverse();

	cout << "length:" << list1->ListLength() << endl;

	list1->GetElem(0, &temp);
	cout << "temp:" << temp << endl;

	delete list1;
	list1 = NULL;
	return 0;
}

List::List(int size)
{
	m_iSize = size;
	m_pList = new int[m_iSize];
	m_iLength = 0;
}

List::~List()
{
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	m_iLength = 0;
}

bool List::ListEmpty()
{
	return m_iLength == 0 ? true : false;
}

int List::ListLength()
{
	return m_iLength;
}
bool List::GetElem(int i, int *e)
{
	if(i < 0 || i >= m_iSize)
	{
		return false;
	}
	*e = m_pList[i];
	return true;
}

int List::LocateElem(int *e)
{
	for(int i = 0; i < m_iLength; i++)
	{
		if(m_pList[i] == *e)
		{
			return i;
		}
	}
	return -1;
}

bool List::PrevElem(int *currentElem, int *preElem)
{
	int temp = LocateElem(currentElem);
	// 指定元素没有找到
	if(temp == -1)
	{
		return false;
	}
	else
	{
		// 载链表首位，没有前驱
		if(temp == 0)
		{
			return false;
		}
		else
		{
			*preElem = m_pList[temp - 1];
			return true;
		}
	}
}

bool List::NextElem(int *currentElem, int *nextElem)
{
	int temp = LocateElem(currentElem);
	if(temp == -1)
	{
		return false;
	}
	else
	{
		// 在链表尾部，没有后继
		if(temp == m_iLength - 1)
		{
			return false;
		}
		else
		{
			*nextElem = m_pList[temp + 1];
			return true;
		}
	}	
}

void List::ListTraverse()
{
	for(int i = 0; i < m_iLength; i++)
	{
		cout << m_pList[i] << endl;
	}
}

bool List::ListInsert(int i, int *e)
{
	// 不能随便插入
	if(i < 0 || i >= m_iSize)
	{
		return false;
	}
	// 移动
	for(int k = m_iLength - 1; k >= i; k--)
	{
		m_pList[k+1] = m_pList[k];
	}
	// 插入
	m_pList[i] = *e;
	// 长度加一
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, int *e)
{
	if(i < 0 || i >= m_iLength)
	{
		return false;
	}
	// 获取要删除的元素
	*e = m_pList[i];

	// 从删除点往后的数据向前移动
	for(int k = i + 1; k > m_iLength; k++)
	{
		m_pList[k - 1] = m_pList[k];
	}
	// 长度减一
	m_iLength--;
	return true;
}
