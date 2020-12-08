#include "CalendarDate.h"

//----------ÑÅÒÒÅĞÛ----------
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


//----------ÃÅÒÒÅĞÛ----------
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
	case 1: month = " ÿíâ."; break;
	case 2: month = " ôåâ."; break;
	case 3: month = " ìàğò."; break;
	case 4: month = " àïğ."; break;
	case 5: month = " ìàé."; break;
	case 6: month = " èşí."; break;
	case 7: month = " èşë."; break;
	case 8: month = " àâã."; break;
	case 9: month = " ñåíò."; break;
	case 10: month = " îêò."; break;
	case 11: month = " íîÿ."; break;
	case 12: month = " äåê."; break;
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