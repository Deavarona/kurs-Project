#ifndef CALENDARDATE_H
#define CALENDARDATE_H
#include "Calendar.h"

class CalendarDate : public Calendar
{
private:
	int m_day;
	int m_month;
	int m_year;
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
};

#endif