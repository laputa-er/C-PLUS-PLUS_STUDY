#include <iostream>
#include "Tank.h"
using namespace std;

int main(void)
{
	Tank t1('A');
	cout << Tank::getCount() << endl;
	cout << t1.getCount() << endl;

	Tank *p = new Tank('B');
	cout << p->getCount() << endl;

	delete p;
	p = NULL;

	cout << Tank::getCount() << endl;
	return 0;
}