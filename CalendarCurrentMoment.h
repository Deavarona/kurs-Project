#ifndef CALENDARCURRENTMOMENT_H
#define CALENDARCURRENTMOMENT_H
#include "Note.h"
#include <ctime>

class CalendarCurrentMoment: public Note
{
protected:
	int m_current_day;
	int m_current_month;
	int m_current_year;
	int m_current_minute;
	int m_current_hour;
public:
	CalendarCurrentMoment();
};

#endif