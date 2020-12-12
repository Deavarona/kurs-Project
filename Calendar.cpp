#include "Calendar.h"

void Calendar::createNote()
{
	std::cout << "����� �������!" << std::endl;

	std::cout << "��� �������: ";
	std::string name_of_note = inputString();
	setNoteName(name_of_note);

	std::cout << "��������: ";
	std::string note_content = inputString();
	setNoteContent(note_content);

	int year, month, day;
	int hour, minute;

	std::cout << "�������� �������?" << std::endl;
	std::cout << "1. ��������!" << std::endl;
	std::cout << "����� ���� ������: �� ���������!" << std::endl;

	if (_getch() == '1')
	{
		std::cout << "���������� ����� ��������� ������." << std::endl;
		std::cout << "����." << std::endl;
		year = inputYear();
		month = inputMonth();
		day = inputDay();
		std::cout << "�����." << std::endl;
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

//---------- � � � � ----------

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
	int day;
	while (1)
	{
		std::cout << "����: ";
		try
		{
			//���� ��������
			day = inputIntegerNumber();

			//����� ���������� ��������
			if (day < 1 || day>31)
			{
				throw 1;
			}

			//������� ���������� �������� (� ����������� �� ������)
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
			std::cout << "���������� ������!" << std::endl;
			if (logical_error == 1)
			{
				std::cout << "������� ����� �� 1 �� 31." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "� ������" << defineMonth() << " 30 ����!" << std::endl;
			}
			if (logical_error == 3)
			{
				std::cout << "� ������� �� ����� ���� ������ 29 ����!" << std::endl;
			}
			if (logical_error == 4)
			{
				std::cout << m_year << " �� �������� ����������. � ������� 28 ����." << std::endl;
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
		std::cout << "�����: ";
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
				std::cout << "� ���� 12 �������. ������� ����� �� 1 �� 12." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "�� ������ ������ �����" << defineMonth() << "." << std::endl;
				std::cout << "����������, �� ���������� �������� ������������ ������." << std::endl;
			}
		}
	}

}
int Calendar::inputYear()
{
	int year;
	while (1)
	{
		std::cout << "Year: ";
		try
		{
			year = inputIntegerNumber();
			if (year < m_current_year)
			{
				throw 1;
			}
		}
		catch (const int logical_error)
		{
			if (logical_error == 1)
			{
				std::cout << "�� ����� " << m_current_year << " ���!" << std::endl;
				std::cout << "����������, �� ���������� �������� ������������ ������." << std::endl;
			}
		}
	}
}


//---------- � � � � � ----------

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
	int minute;
	while (1)
	{
		std::cout << "������: ";
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
				std::cout << "���������� ������! � ����� 60 �����." << std::endl;
				std::cout << "������� ���������� ����� �� 0 �� 59!" << std::endl;
			}
		}
	}
}
int Calendar::inputHour()
{
	int hour;
	while (1)
	{
		std::cout << "����: ";
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
				std::cout << "���������� ������! � ������ 24 ����." << std::endl;
				std::cout << "������� �������� �� 0 �� 23." << std::endl;
			}
			if (logical_error == 2)
			{
				std::cout << "� 24-������� ������� 12 ����� ���� ������������ ��� 00." << std::endl;
				std::cout << "����������, ��������� ����, ����� �������� 0." << std::endl;
			}
		}
	}
}

//---------- � � � � � -----------

void Calendar::writeToFile(std::string name_of_file)
{
	try
	{
		std::ofstream file(name_of_file, std::ios::app);
		if (!file.is_open())
		{
			if (!isFileExist(DATABASE_FILE_NAME))
			{
				std::cout << "������� ���� ���� � �� ��� ���� ����� �� ��� �����?" << std::endl;
				std::cout << "�� �������� ������ ��� ���� ���� ���� �?" << std::endl;
				std::cout << "��� ����, ��������, �������, ���, ��� ���� ��" << std::endl;
				throw 1;
			}
		}
		file << m_note_name << SPECIAL_SYMBOL << " " << m_note_content << SPECIAL_SYMBOL << " " << m_status << " " << m_priority << " " << m_year << " " << m_month << " " <<
			m_month << " " << m_day << " " << m_hour << " " << m_minute << std::endl;
		file.close();
	}
	catch (const int file_error)
	{
		if (file_error == 1)
		{
			createFile(DATABASE_FILE_NAME);
			std::ofstream new_file(name_of_file, std::ios::app);
			new_file.close();
			std::cout << "�������� ���������... ���� �� ����� ���� ������." << std::endl;
			std::cout << "��������� �������" << std::endl;
		}
	}
}
void Calendar::readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes)
{
	try
	{
		std::ifstream file(name_of_file, std::ios::app);
		if (!file.is_open())
		{
			if (!isFileExist(DATABASE_FILE_NAME))
			{
				std::cout << "������� ���� ���� � �� ��� ���� ����� �� ��� �����?" << std::endl;
				std::cout << "�� �������� ������ ��� ���� ���� ���� �?" << std::endl;
				std::cout << "��� ����, ��������, �������, ���, ��� ���� ��" << std::endl;
				throw 1;
			}
		}

		for (int i = 0; i < number_of_notes; i++)
		{
			std::getline(file, note.at(i).m_note_name, SPECIAL_SYMBOL);
			std::getline(file, note.at(i).m_note_content, SPECIAL_SYMBOL);
			file >> note.at(i).m_status;
			file >> note.at(i).m_priority;
			file >> note.at(i).m_year;
			file >> note.at(i).m_month;
			file >> note.at(i).m_day;
			file >> note.at(i).m_hour;
			file >> note.at(i).m_minute;
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
			std::cout << "�������� ���������... ���� �� ����� ���� ������." << std::endl;
			std::cout << "��������� �������" << std::endl;
		}
	}
}