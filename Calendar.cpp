#include "Calendar.h"
#include "CalendarCurrentMoment.h"

Calendar::Calendar()
{
	
}

void Calendar::createNote()
{
	std::cout << "Имя заметки: ";
	std::string name_of_note;
	std::getline(std::cin, name_of_note);
	setNoteName(name_of_note);

	std::cout << "Описание: ";
	std::string note_content;
	std::getline(std::cin, note_content);
	setNoteContent(note_content);

	std::cout << "Дедлайн задачи: " << std::endl;
	int year = inputYear();
	setYear(year);
	int month = inputMonth();
	setMonth(month);
	int day = inputDay();
	setDay(day);

	int hour = inputHour();
	setHour(hour);
	int minute = inputMinute();
	setMinute(minute);
}

//----------СЕТТЕРЫ----------
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


//----------ГЕТТЕРЫ----------
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
	case 1: month = " янв."; break;
	case 2: month = " фев."; break;
	case 3: month = " март."; break;
	case 4: month = " апр."; break;
	case 5: month = " май."; break;
	case 6: month = " июн."; break;
	case 7: month = " июл."; break;
	case 8: month = " авг."; break;
	case 9: month = " сент."; break;
	case 10: month = " окт."; break;
	case 11: month = " ноя."; break;
	case 12: month = " дек."; break;
	}
	return month;
}


//--------------------
int Calendar::inputDay()
{
	int day;
	while (1)
	{
		std::cout << "Day: ";
		day = inputNumber();
		switch (m_month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
		{
			if (day >= 1 && day <= 31)
			{
				return day;
			}
			else
			{
				std::cout << "Логическая ошибка! В месяце " << defineMonth() << " 31 день!" << std::endl;
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			if (day >= 1 && day <= 30)
			{
				return day;
			}
			else
			{
				std::cout << "Логическая ошибка! В месяце " << defineMonth() << " 30 дней!" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (day >= 0)
			{
				if (day <= 29 && m_year % 4 == 0 || day <= 28)
				{
					return day;
				}
			}
			else
			{
				std::cout << "Логическая ошибка! В феврале 28 дней!" << std::endl;
			}
		}
		}
	}
	return day;
}

int Calendar::inputMonth()
{
	while (1)
	{
		std::cout << "Month: ";
		int month = inputNumber();
		if (month >= 1 && month <= 12)
		{
			return month;
		}
		else
		{
			std::cout << "Логическая ошибка! Введите номер месяца от 1 (янв.) до 12 (дек.)" << std::endl;
		}
	}
	
}

int Calendar::inputYear()
{
	while (1)
	{
		std::cout << "Year: ";
		int year = inputNumber();
		if (year >= m_current_year)
		{
			return year;
		}
		else
		{
			std::cout << "Логическая ошибка! Сегодня " << m_current_year << " год." << std::endl;
		}
	}
}



//----------СЕТТЕРЫ----------
void Calendar::setMinute(int minute)
{
	m_minute = minute;
}

void Calendar::setHour(int hour)
{
	m_hour = hour;
}


//----------ГЕТТЕРЫ----------
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
	while (1)
	{
		std::cout << "Minute: ";
		int minute = inputNumber();
		if (minute >= 0 && minute <= 59)
		{
			return minute;
		}
		else
		{
			std::cout << "Логическая ошибка! В часах 60 минут. Введите количество минут от 0 до 59!" << std::endl;
		}
	}
	
	int minute;
	std::cin >> minute;
	return minute;
}

int Calendar::inputHour()
{
	while (1)
	{
		std::cout << "Hour: ";
		int hour = inputNumber();
		if (hour >= 0 && hour <= 23)
		{
			return hour;
		}
		else
		{
			std::cout << "Логическая ошибка! В сутках 24 часа. Введите количество часов от 0 до 23!" << std::endl;
		}
	}
}