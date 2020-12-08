#include "CalendarDate.h"

//----------�������----------
void CalendarDate::setDay(int day)
{
	m_day = day;
}

void CalendarDate::setMonth(int month)
{
	m_month = month;
}

void CalendarDate::setYear(int year)
{
	m_year = year;
}


//----------�������----------
int CalendarDate::getDay()
{
	return m_day;
}

int CalendarDate::getMonth()
{
	return m_month;
}

int CalendarDate::getYear()
{
	return m_year;
}


//--------------------
std::string CalendarDate::defineMonth()
{
	std::string month;
	switch (m_month)
	{
	case 1: month = " ���."; break;
	case 2: month = " ���."; break;
	case 3: month = " ����."; break;
	case 4: month = " ���."; break;
	case 5: month = " ���."; break;
	case 6: month = " ���."; break;
	case 7: month = " ���."; break;
	case 8: month = " ���."; break;
	case 9: month = " ����."; break;
	case 10: month = " ���."; break;
	case 11: month = " ���."; break;
	case 12: month = " ���."; break;
	}
	return month;
}


//--------------------
int CalendarDate::inputDay()
{
	int day;
	std::cin >> day;
	return day;
}

int CalendarDate::inputMonth()
{
	int month;
	std::cin >> month;
	return month;
}

int CalendarDate::inputYear()
{
	int year;
	std::cin >> year;
	return year;
}