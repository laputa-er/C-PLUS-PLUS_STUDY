#include <iostream>
#include "Soldier.h"
using namespace std;

Soldier::Soldier()
{
	cout << "Soldier()" << endl;
}

Soldier::~Soldier()
{
	cout << "~Soldier()" << endl;
}

void Soldier::work()
{
	cout << "Soldier::work()" << endl;
}

void Soldier::play()
{
	cout << "Soldier::work" << endl;
}