#include "ThisMoment.h"

ThisMoment::ThisMoment()
{
	defineThisMoment();
}
void ThisMoment::defineThisMoment()
{
	right_now = time(NULL);
	right_now_struct;
	localtime_s(&right_now_struct, &right_now);

	m_current_day = right_now_struct.tm_mday;
	m_current_month = right_now_struct.tm_mon + 1;
	m_current_year = right_now_struct.tm_year + 1900;

	m_current_minute = right_now_struct.tm_min;
	m_current_hour = right_now_struct.tm_hour;
}
int ThisMoment::getCurrentYear()
{
	return m_current_year;
}
int ThisMoment::getCurrentMonth()
{
	return m_current_month;
}
int ThisMoment::getCurrentDay()
{
	return m_current_day;
}
int ThisMoment::defineMaxDayInThatMonth(int month, int year)
{
	bool is_year_leap=false;
	if (year % 4 == 0)
	{
		is_year_leap = true;
	}
	if (year % 100 == 0)
	{
		is_year_leap = false;
	}
	if (year % 400 == 0)
	{
		is_year_leap = true;
	}
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
	{
		if (is_year_leap)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	}
}
void ThisMoment::showCalendarThisMonth(int month, int year)
{
	int max_day = defineMaxDayInThatMonth(month, year);
	month -= 1;
	year -= 1900;

	tm mytimestruct;
	time_t mytime;
	time(&mytime);
	localtime_s(&mytimestruct, &mytime);

	mytimestruct.tm_year = year;
	mytimestruct.tm_mon = month;
	mktime(&mytimestruct);

	std::cout << month_name[month] << " " << year + 1900 << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << day_week_name[i] << " ";
	}
	std::cout << std::endl;
	//std::cout << "ом" << " " << "бр" << " " << "яп" << " " << "вр" << " " << "ор" << " " << "яа" << " " << "бя" << std::endl;
	for (int t = 1; t <= max_day; t++)
	{
		mytimestruct.tm_mday = t;
		mktime(&mytimestruct);

		if (t == 1 && mytimestruct.tm_wday != 1)
		{
			if (mytimestruct.tm_wday == 0)
			{
				for (int i = 0; i <= 6; i++)
				{
					std::cout << std::setw(3) << " ";
				}
			}
			else
				for (int i = 0; i < mytimestruct.tm_wday - 1; i++)
				{
					std::cout << std::setw(3) << " ";
				}
		}

		std::cout << std::setw(2) << t << " ";
		if (mytimestruct.tm_wday == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
}
void ThisMoment::showCalendarOnlyMonth()
{
	showCalendarThisMonth(m_current_month, m_current_year);
}