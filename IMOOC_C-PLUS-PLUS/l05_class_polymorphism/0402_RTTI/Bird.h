#ifndef BIRD_H_
#define BIRD_H_
#include "Flyable.h"
#include <string>
using namespace std;

class Bird:public Flyable
{
public:
	void foraging();
	virtual void takeOff();
	virtual void land();
};

#endif