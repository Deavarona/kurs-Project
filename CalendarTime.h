#ifndef CALENDARTIME_H
#define CALENDARTIME_H
#include "Calendar.h"

class CalendarTime : public Calendar
{
private:
	int m_minute;
	int m_hour;
public:
	//-----�������-----
	void setMinute(int minute);
	void setHour(int hour);
	//-----�������-----
	int getMinute();
	int getHour();
	//----------
	int inputMinute();
	int inputHour();
};

#endif