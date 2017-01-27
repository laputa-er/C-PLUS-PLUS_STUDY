#include "Person.h"

// 采用公有继承的的方式
class Soldier : public Person
{
public:
	Soldier();
	~Soldier();
	void work();
	void play();
};