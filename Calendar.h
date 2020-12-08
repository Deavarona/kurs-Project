#ifndef CALENDAR_H
#define CALENDAR_H
#include "CalendarCurrentMoment.h"

class Calendar:public CalendarCurrentMoment
{
public:
	Calendar();

private:
	int m_day;
	int m_month;
	int m_year;
public:
	//-----�������-----
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//-----�������-----
	int getDay();
	int getMonth();
	int getYear();
	//----------
	std::string defineMonth();
	int inputDay();
	int inputMonth();
	int inputYear();

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