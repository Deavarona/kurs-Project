#include "Calendar.h"

void Calendar::createNote()
{
	std::cout << "НОВАЯ ЗАМЕТКА!" << std::endl;

	std::cout << "Имя заметки: ";
	std::string name_of_note = inputString();
	setNoteName(name_of_note);

	std::cout << "Описание: ";
	std::string note_content = inputString();
	setNoteContent(note_content);

	int year, month, day;
	int hour, minute;

	std::cout << "Добавить дедлайн?" << std::endl;
	std::cout << "1. Добавить!" << std::endl;
	std::cout << "Любой иной символ: Не добавлять!" << std::endl;

	if (_getch() == '1')
	{
		std::cout << "Добавление срока выполения задачи." << std::endl;
		std::cout << "ДАТА." << std::endl;
		year = inputYear();
		month = inputMonth();
		day = inputDay();
		std::cout << "ВРЕМЯ." << std::endl;
		hour = inputHour();
		minute = inputMinute();
	}
	else
	{
		year = DEFAULT_VALUE;
		month = DEFAULT_VALUE;
		day = DEFAULT_VALUE;
		hour = DEFAULT_VALUE;
		minute = DEFAULT_VALUE;
	}

	setYear(year);
	setMonth(month);
	setDay(day);
	setHour(hour);
	setMinute(minute);
}

//---------- Д А Т А ----------

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

std::string Calendar::defineNameOfMonth()
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
		std::cout << "День: ";
		try
		{
			//Ввод значения
			day = inputIntegerNumber();

			//Общая логическая проверка
			if (day < 1 || day>31)
			{
				throw 1;
			}

			//Частная логическая проверка (в зависимости от месяца)
			switch (m_month)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			{
				break;
			}
			case 4: case 6: case 9: case 11:
			{
				if (day > 30)
				{
					throw 2;
				}
				break;
			}
			case 2:
				if (day > 29)
				{
					throw 3;
				}
				if (day == 29 && m_year % 4 != 0)
				{
					throw 4;
				}
				break;
			}
			break;
		}
		catch (const int logical_error)
		{
			std::cout << "Логическая ошибка!" << std::endl;
			if (logical_error == 1)
			{
				std::cout << "Введите число от 1 до 31." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "В месяце" << defineNameOfMonth() << " 30 дней!" << std::endl;
			}
			if (logical_error == 3)
			{
				std::cout << "В феврале не может быть больше 29 дней!" << std::endl;
			}
			if (logical_error == 4)
			{
				std::cout << m_year << " не является високосным. В феврале 28 дней." << std::endl;
			}
		}
	}
	return day;
}
int Calendar::inputMonth()
{
	int month;
	while (1)
	{
		std::cout << "Месяц: ";
		try
		{
			month = inputIntegerNumber();
			if (month < 1 || month >12)
			{
				throw 1;
			}
			if (month < m_current_month)
			{
				throw 2;
			}
			return month;
		}
		catch(const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "В году 12 месяцев. Введите число от 1 до 12." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "На данный момент месяц" << defineNameOfMonth() << "." << std::endl;
				std::cout << "Пожалуйста, не создавайте заведомо просроченные задачи." << std::endl;
			}
		}
	}

}
int Calendar::inputYear()
{
	int year;
	while (1)
	{
		std::cout << "Год: ";
		try
		{
			year = inputIntegerNumber();
			if (year < m_current_year)
			{
				throw 1;
			}
			return year;
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "На дворе " << m_current_year << " год!" << std::endl;
				std::cout << "Пожалуйста, не создавайте заведомо просроченные задачи." << std::endl;
			}
		}
	}
}


//---------- В Р Е М Я ----------

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
	int minute;
	while (1)
	{
		std::cout << "Минуты: ";
		try
		{
			minute = inputIntegerNumber();
			if (minute < 0 || minute>59)
			{
				throw 1;
			}
			return minute;
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "Логическая ошибка! В часах 60 минут." << std::endl;
				std::cout << "Введите количество минут от 0 до 59!" << std::endl;
			}
		}
	}
}
int Calendar::inputHour()
{
	int hour;
	while (1)
	{
		std::cout << "Часы: ";
		try
		{
			hour = inputIntegerNumber();
			if (hour < 0 || hour > 23)
			{
				throw 1;
			}
			if (hour == 24)
			{
				throw 2;
			}
			return hour;
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "Логическая ошибка! В сутках 24 часа." << std::endl;
				std::cout << "Введите значение от 0 до 23." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "В 24-часовом формате 12 часов ночи обозначается как 00." << std::endl;
				std::cout << "Пожалуйста, повторите ввод, введя значение 0." << std::endl;
			}
		}
	}
}

//---------- Ф А Й Л Ы -----------

void Calendar::saveNoteInFile(std::string name_of_file)
{
	try
	{
		std::ofstream file(name_of_file, std::ios::app);
		if (!file.is_open())
		{
			if (!isFileExist(DATABASE_FILE_NAME))
			{
				std::cout << "Ублюдок мать твою а ну иди сюда решил ко мне лезть?" << std::endl;
				std::cout << "Ты засранец удалил мой файл мать твою а?" << std::endl;
				std::cout << "Иди сюда, мерзавец, негодяй, гад, иди сюда ты" << std::endl;
				throw 1;
			}
		}
		file << m_note_name << SPECIAL_SYMBOL << " " << m_note_content << SPECIAL_SYMBOL << " " << m_status << " " << m_priority << " " 
			<< m_year << " " << m_month << " " << m_day << " " << m_hour << " " << m_minute << std::endl;
		file.close();
	}
	catch (const int file_error)
	{
		if (file_error == 1)
		{
			createFile(DATABASE_FILE_NAME);
			std::ofstream new_file(name_of_file, std::ios::app);
			new_file.close();
			std::cout << "Возникли неполадки... Файл не может быть открыт." << std::endl;
			std::cout << "Повторите попытку" << std::endl;
		}
	}
}
void Calendar::readAllNotesFromFile(std::string name_of_file, std::vector <Calendar>&notes, int number_of_notes)
{
	try
	{
		std::ifstream file(name_of_file, std::ios::in);
		if (!file.is_open())
		{
			if (!isFileExist(DATABASE_FILE_NAME))
			{
				std::cout << "Ублюдок мать твою а ну иди сюда решил ко мне лезть?" << std::endl;
				std::cout << "Ты засранец удалил мой файл мать твою а?" << std::endl;
				std::cout << "Иди сюда, мерзавец, негодяй, гад, иди сюда ты" << std::endl;
				throw 1;
			}
		}
		std::string trash;
		//std::cout << "Количество записей: " << number_of_notes << std::endl;
		for (int i = 0; i < number_of_notes; i++)
		{
			std::getline(file, notes.at(i).m_note_name, '\'');
			std::getline(file, trash, ' ');
			std::getline(file, notes.at(i).m_note_content, SPECIAL_SYMBOL);
			file >> notes.at(i).m_status;
			file >> notes.at(i).m_priority;
			file >> notes.at(i).m_year;
			file >> notes.at(i).m_month;
			file >> notes.at(i).m_day;
			file >> notes.at(i).m_hour;
			file >> notes.at(i).m_minute;
			std::getline(file, trash, '\n');
		}

		file.close();
	}
	catch (const int file_error)
	{
		if (file_error == 1)
		{
			createFile(DATABASE_FILE_NAME);
			std::ofstream new_file(name_of_file, std::ios::app);
			new_file.close();
			std::cout << "Возникли неполадки... Файл не может быть открыт." << std::endl;
			std::cout << "Повторите попытку" << std::endl;
		}
	}
}

void Calendar::showNote(Calendar&note)
{
	std::cout << "Имя заметки: " << note.m_note_name << std::endl;
	std::cout << "Описание: " << note.m_note_content << std::endl;
	if (note.m_status)
	{
		std::cout << "Статус: выполнена." << std::endl;
	}
	else
	{
		std::cout << "Приоритет: " << note.m_priority << std::endl;
	}
	if (note.m_year != DEFAULT_VALUE)
	{
		std::cout << "Дедлайн: " << note.m_year << "/" << note.m_month << "/" << note.m_day << " " 
			<< note.m_hour << ":" << note.m_minute << std::endl;
	}
}

void Calendar::showAllNotes(std::vector <Calendar>& note, int number_of_notes)
{
	for (int i = 0; i < number_of_notes; i++)
	{
		note.at(i).showNote(note.at(i));
		std::cout << std::endl;
	}
}