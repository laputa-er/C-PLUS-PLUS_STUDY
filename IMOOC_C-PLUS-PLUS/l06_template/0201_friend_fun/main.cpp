#include <iostream>
#include "Time.h"
#include "Match.h"

using namespace std;

void printTime(Time &t);

int main(void)
{
	Time t(6, 34, 25);
	printTime(t);

	Match m;
	m.printTime(t);
	
	return 0;
}

void printTime(Time &t)
{
	cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond << endl;
}