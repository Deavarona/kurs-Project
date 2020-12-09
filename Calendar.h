#ifndef CALENDAR_H
#define CALENDAR_H
#include "CalendarCurrentMoment.h"
#include "Tools.h"

class Calendar:public CalendarCurrentMoment
{
public:
	Calendar();

private:
	int m_day=UNKNOWN_VALUE;
	int m_month=UNKNOWN_VALUE;
	int m_year=UNKNOWN_VALUE;
public:
	//-----Сеттеры-----
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//-----Геттеры-----
	int getDay();
	int getMonth();
	int getYear();
	//----------
	std::string defineMonth();
	int inputDay();
	int inputMonth();
	int inputYear();

private:
	int m_minute=UNKNOWN_VALUE;
	int m_hour=UNKNOWN_VALUE;
public:
	//-----Сеттеры-----
	void setMinute(int minute);
	void setHour(int hour);
	//-----Геттеры-----
	int getMinute();
	int getHour();
	//----------
	int inputMinute();
	int inputHour();
};

#endif