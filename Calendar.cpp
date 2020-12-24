#include "Calendar.h"

void Calendar::createNote()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\tН О В А Я   З А Д А Ч А" << std::endl;
	std::cout << LINE_MENU << std::endl;

	std::cout << "Имя: ";
	std::string name_of_note = inputString();
	setNoteName(name_of_note);

	std::cout << "Описание: ";
	std::string note_content = inputString();
	setNoteContent(note_content);

	int year, month, day;
	int hour, minute;

	std::cout << LINE_MENU << std::endl;
	std::cout << "\tДобавить дедлайн?" << std::endl;
	std::cout << "\t1 - Добавить." << std::endl;
	std::cout << "\tЛюбой иной символ: Не добавлять." << std::endl;
	std::cout << LINE_MENU << std::endl;

	if (_getch() == '1')
	{
		std::cout << "\tДобавление срока выполения задачи." << std::endl;
		std::cout << "ДАТА." << std::endl;
		year = inputYear();
		month = inputMonth(year);
		day = inputDay(month, year);
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
	setPriority(calculatePriority());
}
int Calendar::calculatePriority()
{
	std::cout << "Расчет приоритета." << std::endl;

	int importance = 1;
	std::cout << "-------" << std::endl;
	std::cout << "Задача важная?" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "1 - Важная." << std::endl;
	std::cout << "Любой символ: Не важная." << std::endl;
	if (_getch() == '1')
	{
		importance = 2;
	}

	int complexity = 1;
	std::cout << "-------" << std::endl;
	std::cout << "Задача сложная?" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "1 - Сложная." << std::endl;
	std::cout << "Любой символ: Не сложная." << std::endl;
	if (_getch() == '1')
	{
		complexity = 2;
	}

	int urgency = 1;
	double seconds_left = timeBeforeDeadline();
	if (seconds_left < 3 * 24 * 60 * 60)
	{
		urgency = 2;
	}
	if (seconds_left < 3 * 60 * 60)
	{
		urgency = 3;
	}
	int priority = importance * complexity * urgency;
	priority=trunc(priority / 3);
	return priority;
}
double Calendar::timeBeforeDeadline()
{
	time_t settime = time(NULL);
	tm mysettime;
	localtime_s(&mysettime, &settime);
	mysettime.tm_year = m_year;
	mysettime.tm_mon = m_month;
	mysettime.tm_mday = m_day;
	mysettime.tm_hour = m_hour;
	mysettime.tm_min = m_minute;
	double seconds_left = difftime(mktime(&right_now_struct), mktime(&mysettime));
	return seconds_left;
}
void addNote()
{
	Calendar note;
	note.createNote();
	system("cls");
	note.showNote(note);
	if (isActionConfirmed(MESSAGE_SAVE))
	{
		note.saveNoteInFile(DATABASE_FILE_NAME);
		std::cout << "Успешно сохранено!" << std::endl;
	}
	Sleep(1000);
	system("cls");
}

//--------------------

int Calendar::chooseTheNoteNumber(std::vector <Calendar>& notes, int number_of_notes)
{
	Calendar note;
	int note_number;
	while (1)
	{
		try
		{
			note.showAllNotes(notes, number_of_notes);
			std::cout << std::endl;
			std::cout << "Выберите задачу, которую хотите изменить: " << std::endl;
			std::cout << "Номер задачи: ";
			note_number = inputIntegerNumber();
			if (note_number > number_of_notes || note_number<1)
			{
				throw 1;
			}
			note_number--;
			break;
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				system("cls");
				std::cout << "Всего заметок: " << number_of_notes << std::endl;
				std::cout << "Выберите номер от 1 до " << number_of_notes << std::endl;
			}
		}
	}
	return note_number;
}

//-------------------

void Calendar::todayTasks()
{
	Calendar note;
	int number_of_notes = defineNumberOfNotesInFile(DATABASE_FILE_NAME);
	std::vector <Calendar> notes(number_of_notes);
	note.readAllNotesFromFile(DATABASE_FILE_NAME, notes, number_of_notes);

	int year = note.getCurrentYear();
	int month = note.getCurrentMonth();
	int day = note.getCurrentDay();

	std::cout << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Ваши задачи на сегодня: " << std::endl;
	std::cout << "==========================" << std::endl;
	int number_of_tasks = 0;
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_year == year && notes.at(i).m_month == month && notes.at(i).m_day == day)
		{
			notes.at(i).showNote(notes.at(i));
			number_of_tasks++;
		}
	}
	if (number_of_tasks == 0)
	{
		std::cout << "Задач на сегодня нет!" << std::endl;
	}
	std::cout << "==========================" << std::endl;
	std::cout << std::endl;
}
void Calendar::whatTheDayToday()
{
	Calendar note;
	std::cout << "==========================" << std::endl;
	std::cout << "Сегодня " << note.getCurrentDay() << " " << note.defineShortNameOfMonth(getCurrentMonth()) << " "
		<< getCurrentYear() << " года." << std::endl;
	std::cout << "==========================" << std::endl;
}
std::string Calendar::defineShortNameOfMonth(int month_number)
{
	std::string month;
	switch (month_number)
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

int Calendar::inputDay(int month, int year)
{
	Calendar note;
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
			if (day < note.m_current_day && month == note.m_current_month && year == note.m_current_year)
			{
				throw 5;
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
				std::cout << "В месяце" << defineShortNameOfMonth(m_current_month) << " 30 дней!" << std::endl;
			}
			if (logical_error == 3)
			{
				std::cout << "В феврале не может быть больше 29 дней!" << std::endl;
			}
			if (logical_error == 4)
			{
				std::cout << m_year << " не является високосным. В феврале 28 дней." << std::endl;
			}
			if (logical_error == 5)
			{
				std::cout << "Сегодня " << note.m_current_day << " число!" << std::endl;
				std::cout << "Пожалуйста, не создавайте заведомо просроченные задачи!" << std::endl;
			}
		}
	}
	return day;
}
int Calendar::inputMonth(int year)
{
	Calendar note;
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
			if (month < note.m_current_month && year == note.m_current_year)
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
				std::cout << "На данный момент месяц " << defineShortNameOfMonth(m_current_month) << std::endl;
				std::cout << "Не создавайте заведомо просроченные задачи!" << std::endl;
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
			if (year > m_current_year + 100)
			{
				throw 2;
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
			if (logical_error == 2)
			{
				std::cout << "Не заглядывайте так далеко :)" << std::endl;
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
void Calendar::rewriteFile(std::string name_of_file, std::vector<Calendar>& notes, int number_of_notes)
{
	std::ofstream re_file(name_of_file, std::ios::out);
	for (int i = 0; i < number_of_notes; i++)
	{
		re_file << notes.at(i).m_note_name << SPECIAL_SYMBOL << " " << notes.at(i).m_note_content << SPECIAL_SYMBOL << " " 
			<< notes.at(i).m_status << " " << notes.at(i).m_priority << " "
			<< notes.at(i).m_year << " " << notes.at(i).m_month << " " << notes.at(i).m_day << " " 
			<< notes.at(i).m_hour << " " << notes.at(i).m_minute << std::endl;
	}
	re_file.close();
}

//---------- В Ы В О Д ----------

void Calendar::showNote(Calendar&note)
{
	std::cout << "------------" << std::endl;
	std::cout << "Имя заметки: " << note.m_note_name << std::endl;
	std::cout << "Описание: " << note.m_note_content << std::endl;
	if (note.m_status)
	{
		std::cout << "Статус: выполнена." << std::endl;
	}
	else
	{
		std::cout << "Статус: не выполнена." << std::endl;
	}
	std::cout << "Приоритет: " << note.m_priority << std::endl;
	if (note.m_year != DEFAULT_VALUE)
	{
		std::cout << "Дедлайн: " << note.m_year << "/" << note.m_month << "/" << note.m_day << " ";
		if (note.m_hour < 10)
		{
			std::cout << "0" << note.m_hour << ":";
		}
		else
		{
			std::cout << note.m_hour << ":";
		}
		if (note.m_minute < 10)
		{
			std::cout << "0" << note.m_minute << std::endl;
		}
		else
		{
			std::cout << note.m_minute << std::endl;
		}
	}
	std::cout << "---------------" << std::endl;
}
void Calendar::showAllNotes(std::vector <Calendar>& note, int number_of_notes)
{
	for (int i = 0; i < number_of_notes; i++)
	{
		std::cout << i + 1 << ") ";
		note.at(i).showNote(note.at(i));
		std::cout << std::endl;
	}
}
void Calendar::showNotesWithDeadline(std::vector<Calendar>& notes, int number_of_notes)
{
	int number_of_suitable_notes = 0;
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_year != DEFAULT_VALUE)
		{
			number_of_suitable_notes++;
			std::cout << number_of_suitable_notes << ") ";
			notes.at(i).showNote(notes.at(i));
			std::cout << std::endl;
		}
	}
	if (!number_of_suitable_notes)
	{
		std::cout << "Подходящих задач не найдено." << std::endl;
	}
}
void Calendar::showUnfulfilledNotes(std::vector<Calendar>& note, int number_of_notes)
{
	int number_of_suitable_notes = 0;
	for (int i = 0; i < number_of_notes; i++)
	{
		if (!note.at(i).m_status)
		{
			number_of_suitable_notes++;
			std::cout << number_of_suitable_notes << ") ";
			note.at(i).showNote(note.at(i));
			std::cout << std::endl;
		}
	}
	if (!number_of_suitable_notes)
	{
		std::cout << "Подходящих задач не найдено." << std::endl;
	}
}
void Calendar::showNotesThisYear(std::vector<Calendar>& notes, int number_of_notes)
{
	int number_of_suitable_notes = 0;
	Calendar new_note;
	new_note.m_year=new_note.inputYear();
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_year == new_note.m_year)
		{
			number_of_suitable_notes++;
			std::cout << number_of_suitable_notes<< ") ";
			notes.at(i).showNote(notes.at(i));
			std::cout << std::endl;
		}
	}
	if (!number_of_suitable_notes)
	{
		std::cout << "Подходящих задач не найдено." << std::endl;
	}
}
void Calendar::showNotesThisMonth(std::vector<Calendar>& notes, int number_of_notes)
{
	int number_of_suitable_notes = 0;
	Calendar new_note;
	new_note.m_year=new_note.inputYear();
	new_note.m_month=new_note.inputMonth(0);
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_month == new_note.m_month && notes.at(i).m_year==new_note.m_year)
		{
			number_of_suitable_notes++;
			std::cout << number_of_suitable_notes << ") ";
			notes.at(i).showNote(notes.at(i));
			std::cout << std::endl;
		}
	}
	if (!number_of_suitable_notes)
	{
		std::cout << "Подходящих задач не найдено." << std::endl;
	}
}
void Calendar::showNotesThisDay(std::vector<Calendar>& notes, int number_of_notes)
{
	int number_of_suitable_notes = 0;
	Calendar new_note;
	new_note.m_year=new_note.inputYear();
	new_note.m_month=new_note.inputMonth(0);
	new_note.m_day=new_note.inputDay(0,0);
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_day == new_note.m_day && notes.at(i).m_month == new_note.m_month && notes.at(i).m_year == new_note.m_year)
		{
			number_of_suitable_notes++;
			std::cout << number_of_suitable_notes<< ") ";
			notes.at(i).showNote(notes.at(i));
			std::cout << std::endl;
		}
	}
	if (!number_of_suitable_notes)
	{
		std::cout << "Подходящих задач не найдено." << std::endl;
	}
}
void Calendar::showNotesWithoutDeadline()
{
	int number_of_notes = defineNumberOfNotesInFile(DATABASE_FILE_NAME);
	std::vector<Calendar> notes(number_of_notes);
	notes.at(0).readAllNotesFromFile(DATABASE_FILE_NAME, notes, number_of_notes);

	std::cout << "==========================" << std::endl;
	std::cout << "Ваши заметки без дедлайна: " << std::endl;
	for (int i = 0; i < number_of_notes; i++)
	{
		if (notes.at(i).m_year == DEFAULT_VALUE)
		{
			showNote(notes.at(i));
		}
	}
	std::cout << "==========================" << std::endl;
}
void Calendar::sortPriority(std::vector<Calendar>&note, int number_of_notes)
{
	for (int i = 0; i < number_of_notes; i++)
	{
		for (int j = 0; j < number_of_notes - 1; j++)
		{
			if (note.at(j).m_priority < note.at(j + 1).m_priority)
			{
				std::swap(note.at(j).m_priority, note.at(j + 1).m_priority);
			}
		}
	}

	note.at(0).showAllNotes(note, number_of_notes);
}

//---------- Р Е Д А К Т И Р О В А Н И Е ----------

void Calendar::editNoteName(Calendar&note)
{
	std::cout << "Новое имя: ";
	note.setNoteName(note.inputString());
}
void Calendar::editNoteContent(Calendar& note)
{
	std::cout << "Новое описание: ";
	note.setNoteContent(note.inputString());
}
void Calendar::editNoteDeadline(Calendar& note)
{
	std::cout << "Новый дедлайн." << std::endl;
	int year, month, day;
	year = inputYear();
	note.setYear(year);
	month = note.inputMonth(year);
	note.setMonth(month);
	day = inputDay(month, year);
	note.setDay(day);
	note.setHour(note.inputHour());
	note.setMinute(note.inputMinute());
}
void Calendar::editNoteStatus(Calendar& note)
{
	bool new_status = !note.getStatus();
	note.setStatus(new_status);
	if (new_status)
	{
		std::cout << "Статус изменен. Задача выполнена." << std::endl;
	}
	else
	{
		std::cout << "Статус изменен. Задача невыполнена." << std::endl;
	}
}
void Calendar::editNotePriority(Calendar& note)
{
	int priority;
	while (1)
	{
		try
		{
			std::cout << "Новый приоритет (от 0 до 4): ";
			priority = inputIntegerNumber();
			if (priority > 4 || priority < 0)
			{
				throw 1;
			}
			note.setPriority(priority);
			break;
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "Недопустимое выражение!" << std::endl;
				std::cout << "Пожалуйста, введите число от 0 до 4 включительно." << std::endl;
			}
		}
	}
}
void Calendar::deleteNote(std::vector<Calendar>& note, int note_number, int&number_of_notes)
{
	for (int i = note_number; i < number_of_notes-1; i++)
	{
		note.at(i) = note.at(i + 1);
	}
	number_of_notes--;
}