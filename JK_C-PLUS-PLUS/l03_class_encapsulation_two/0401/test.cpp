#include <iostream>
using namespace std;

class Coordinate
{
public:
	int m_iX;
	int m_iY;
};

int main(void)
{
	// Coordinate *p = new Coordinate; // Coordinate *p = new Coordinate();
	// p->m_iX = 10; // (*p).m_iX = 10;
	// p->m_iY = 20; // (*p).m_iY = 20;

	// delete p;
	// p = NULL;

	Coordinate coor;
	Coordinate *p = &coor;
	p->m_iX = 10; // (*p).m_iX = 10;
	p->m_iY = 20; // (*p).m_iY = 20;
	
	return 0;
}