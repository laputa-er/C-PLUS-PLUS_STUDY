#ifndef MYSTACK_H
#define MYSTACK_H
class MyStack
{
public:
	MyStack(int size); // 分配内存初始化栈空间，设定栈容量，指定栈顶
	~MyStack(); // 回收栈空间内存
	bool stackEmpty(); // 判空
	bool stackFull(); // 判满
	void clearStack(); // 清空栈
	int stackLength(); // 已有元素数量
	bool push(char elem); // 元素入栈，栈顶下降
	bool pop(char &elem); // 元素出栈，栈顶下降
	void stackTraverse(bool isFromBottom); // 遍历栈
private:
	char *m_pBuffer; // 栈空间指针
	int m_iSize; // 栈容量
	int m_iTop; // 栈顶位置下标(栈底下标为0)
};

#endif