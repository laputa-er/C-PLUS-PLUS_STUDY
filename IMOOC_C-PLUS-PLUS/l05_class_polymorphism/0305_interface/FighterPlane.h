#ifndef FIGHTERPLANE_H_
#define FIGHTERPLANE_H_

#include "Plane.h"
#include "Flyable.h"
#include <string>
using namespace std;

class FighterPlane:public Plane, public Flyable
{
public:
	FighterPlane(string code);
	virtual void takeOff();
	virtual void land();
};

#endif