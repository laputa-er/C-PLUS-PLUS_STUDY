#include <iostream>
#include "MyQueue.h"
using namespace std;

int main(void)
{
	// 创建队列实例
	MyQueue *queue = new MyQueue(4);

	Customer c1("zhangsan", 20);
	Customer c2("lisi", 21);
	Customer c3("wangwu", 22);
	Customer c4("zhaoliu", 23);

	// 插入数据
	queue->EnQueue(c1);
	queue->EnQueue(c2);
	queue->EnQueue(c3);
	queue->EnQueue(c4);

	// 队首出队，赋值给 ele
	Customer ele("", 0);
	queue->DeQueue(ele);
	ele.printInfo();

	// 遍历
	queue->QueueTraverse();

	delete queue;
	queue = NULL;
	return 0;
}
