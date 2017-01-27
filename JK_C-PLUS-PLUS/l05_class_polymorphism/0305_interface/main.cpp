#include <iostream>
#include "Flyable.h"
#include "Plane.h"
#include "FighterPlane.h"

using namespace std;

void flyMatch(Flyable *f1, Flyable *f2)
{
	f1->takeOff();
	f1->land();

	f2->takeOff();
	f2->land();
}

void planeMatch(Plane *p1, Plane *p2)
{
	p1->printCode();
	p2->printCode();
}


int main(void)
{
	FighterPlane f1("001");
	FighterPlane f2("002");

	flyMatch(&f1, &f2);
	planeMatch(&f1, &f2);
	return 0;
}