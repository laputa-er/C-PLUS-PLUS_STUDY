#include <iostream>
#include "MyQueue.h"
using namespace std;

int main(void)
{
	// 创建队列实例
	MyQueue *queue = new MyQueue(4);

	// 插入数据
	queue->EnQueue(3);
	queue->EnQueue(5);
	queue->EnQueue(7);
	queue->EnQueue(9);

	// 队首出队，赋值给 ele
	int ele = 0;
	cout << "DeQueue:" << queue->DeQueue(ele) << endl;

	// 遍历
	queue->QueueTraverse();

	delete queue;
	queue = NULL;
	return 0;
}
