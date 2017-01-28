#include <iostream>
#include "FighterPlane.h"
using namespace std;

FighterPlane::FighterPlane(string code):Plane(code)
{
	cout << "FighterPlane(string code)" << endl;
}
void FighterPlane::takeOff()
{
	cout << "FighterPlace -- takeOff" << endl;
}

void FighterPlane::land()
{
	cout << "FighterPlane -- land" << endl;
}