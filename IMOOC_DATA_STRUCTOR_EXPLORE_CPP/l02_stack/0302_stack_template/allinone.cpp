#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
public:
	MyStack(int size); // 分配内存初始化栈空间，设定栈容量，指定栈顶
	~MyStack(); // 回收栈空间内存
	bool stackEmpty(); // 判空
	bool stackFull(); // 判满
	void clearStack(); // 清空栈
	int stackLength(); // 已有元素数量
	bool push(T elem); // 元素入栈，栈顶下降
	bool pop(T &elem); // 元素出栈，栈顶下降
	void stackTraverse(bool isFromBottom); // 遍历栈
private:
	T *m_pBuffer; // 栈空间指针
	int m_iSize; // 栈容量
	int m_iTop; // 栈顶位置下标(栈底下标为0)
};

int main(void)
{
	// 创建栈实例
	MyStack<char> *pStack = new MyStack<char>(5);

	// 判空
	if(pStack->stackEmpty())
	{
		cout << "栈为空" << endl;
	}

	// 入栈
	pStack->push('a'); // 底
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e'); // 顶

	// 栈长度
	cout << pStack->stackLength() << endl;


	// 判满
	if(pStack->stackFull())
	{
		cout << "栈为满" << endl;
	}

	// 出栈
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;

	// 遍历
	pStack->stackTraverse(true);

	delete pStack;
	pStack = NULL;
	return 0;
}
// 构造器（初始化）
template <typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}

// 释放内存
template <typename T>
MyStack<T>::~MyStack()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

// 判空
template <typename T>
bool MyStack<T>::stackEmpty()
{
	return m_iTop == 0 ? true : false;
}

// 栈满
template <typename T>
bool MyStack<T>::stackFull()
{
	return m_iTop == m_iSize ? true : false;
}

// 清空栈
template <typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;
}

// 获取栈的大小
template <typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}

// 入栈
template <typename T>
bool MyStack<T>::push(T elem)
{
	if(stackFull())
	{
		return false; 
	}
	else
	{
		m_pBuffer[m_iTop] = elem; // 如果 T 的数据成员有指针等情况，则需要考虑定义拷贝构造函数中
		m_iTop++;
		return true;
	}
}

// 出栈
template <typename T>
bool MyStack<T>::pop(T &elem)
{
	if(stackEmpty())
	{
		return false;
	}
	else
	{
		m_iTop--;
		elem = m_pBuffer[m_iTop];
		return true;
	}
}

// 遍历
template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom)
{
	if (isFromBottom)
	{
		for(int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i];
		}
	}
	else
	{
		for(int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i];
		}
	}
}


