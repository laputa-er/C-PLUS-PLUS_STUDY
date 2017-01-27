#include <iostream>
#include "Time.h"
using namespace std;

Time::Time(int hour, int min, int sec)
{
	m_iHour = hour;
	m_iMinute = min;
	m_iSecond = sec;
}

void Time::printTime()
{
	cout << m_iHour << "时" << m_iMinute << "分" << m_iSecond << "秒" << endl;
}