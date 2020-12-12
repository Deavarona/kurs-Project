#ifndef CALENDAR_H
#define CALENDAR_H
#include <conio.h>
#include "ThisMoment.h"
#include "Tools.h"
#include "File.h"

class Calendar: public ThisMoment
{
public:
	//-----����-----
private:
	int m_day = DEFAULT_VALUE; //���� ����� ���������� ������
	int m_month = DEFAULT_VALUE; //����� ����� ���������� ������
	int m_year = DEFAULT_VALUE; //��� ����� ���������� ������
public:
	//-----�������-----
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//-----�������-----
	int getDay();
	int getMonth();
	int getYear();
	//----------
	std::string defineNameOfMonth(); //���������� ����������� �������� ������ �� ��� ������
	int inputDay(); //���� ��� ����� ���������� ������
	int inputMonth(); //���� ������ ����� ���������� ������
	int inputYear(); //���� ���� ����� ���������� ������

	//-----�����-----
private:
	int m_minute = DEFAULT_VALUE; //������ ����� ���������� ������
	int m_hour = DEFAULT_VALUE; //��� ����� ���������� ������
public:
	//-----�������-----
	void setMinute(int minute);
	void setHour(int hour);
	//-----�������-----
	int getMinute();
	int getHour();
	//----------
	int inputMinute(); //���� ������ ����� ���������� ������
	int inputHour(); //���� ���� ����� ���������� ������

public:
	void createNote(); //�������� ������� (����������� ����������� �������)
	void saveNoteInFile(std::string name_of_file); //������ ������ � ����
	void readAllNotesFromFile(std::string name_of_file, std::vector <Calendar>&notes, int number_of_notes); //���������� ���� ����� �� �����
	void showNote(Calendar&note); //������� ������� �� �������
	void showAllNotes(std::vector <Calendar>& note, int number_of_notes); //������� ��� ������� �� �������
};

#endif