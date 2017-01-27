#ifndef PLANE_H_
#define PLANE_H_

#include <string>
using namespace std;

class Plane
{
public:
	Plane(string code);
	void printCode();
private:
	string m_strCode;
};

#endif