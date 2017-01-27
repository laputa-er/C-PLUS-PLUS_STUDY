#include "Person.h"

// 采用公有继承的的方式
class Worker : public Person
{
public:
	Worker();
	~Worker();
	void work();
	int m_iSalary;
};