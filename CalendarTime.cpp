#include "CalendarTime.h"

//----------ÑÅÒÒÅĞÛ----------
void CalendarTime::setMinute(int minute)
{
	m_minute = minute;
}

void CalendarTime::setHour(int hour)
{
	m_hour = hour;
}


//----------ÃÅÒÒÅĞÛ----------
int CalendarTime::getMinute()
{
	return m_minute;
}

int CalendarTime::getHour()
{
	return m_hour;
}


//--------------------
int CalendarTime::inputMinute()
{
	int minute;
	std::cin >> minute;
	return minute;
}

int CalendarTime::inputHour()
{
	int hour;
	std::cin >> hour;
	return hour;
}