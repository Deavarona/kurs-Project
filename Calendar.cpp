#include "Calendar.h"

Calendar::Calendar()
{
	int year = inputYear();
	int month = inputMonth();
	int day = inputDay();

	int hour = inputHour();
	int minute = inputMinute();

	setMinute(minute);
	setHour(hour);
	setDay(day);
	setMonth(month);
	setYear(year);
}


//----------ÑÅÒÒÅĞÛ----------
void Calendar::setDay(int day)
{
	m_day = day;
}

void Calendar::setMonth(int month)
{
	m_month = month;
}

void Calendar::setYear(int year)
{
	m_year = year;
}


//----------ÃÅÒÒÅĞÛ----------
int Calendar::getDay()
{
	return m_day;
}

int Calendar::getMonth()
{
	return m_month;
}

int Calendar::getYear()
{
	return m_year;
}


//--------------------
std::string Calendar::defineMonth()
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
int Calendar::inputDay()
{
	std::cout << "Day: ";
	int day;
	std::cin >> day;
	return day;
}

int Calendar::inputMonth()
{
	std::cout << "Month: ";
	int month;
	std::cin >> month;
	return month;
}

int Calendar::inputYear()
{
	std::cout << "Year: ";
	int year;
	std::cin >> year;
	return year;
}



//----------ÑÅÒÒÅĞÛ----------
void Calendar::setMinute(int minute)
{
	m_minute = minute;
}

void Calendar::setHour(int hour)
{
	m_hour = hour;
}


//----------ÃÅÒÒÅĞÛ----------
int Calendar::getMinute()
{
	return m_minute;
}

int Calendar::getHour()
{
	return m_hour;
}


//--------------------
int Calendar::inputMinute()
{
	std::cout << "Minute: ";
	int minute;
	std::cin >> minute;
	return minute;
}

int Calendar::inputHour()
{
	std::cout << "Hour: ";
	int hour;
	std::cin >> hour;
	return hour;
}