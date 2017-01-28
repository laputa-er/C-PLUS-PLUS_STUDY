#ifndef PLANE_H_
#define PLANE_H_
#include <string>
#include "Flyable.h"

using namespace std;
class Plane:public Flyable
{
public:
	void carry();
	virtual void takeOff();
	virtual void land();
};

#endif