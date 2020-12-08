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


//----------�������----------
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


//----------�������----------
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



//----------�������----------
void Calendar::setMinute(int minute)
{
	m_minute = minute;
}

void Calendar::setHour(int hour)
{
	m_hour = hour;
}


//----------�������----------
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