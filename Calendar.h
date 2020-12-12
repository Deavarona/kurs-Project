#ifndef CALENDAR_H
#define CALENDAR_H
#include "ThisMoment.h"
#include "Constants.h"
#include "Tools.h"
#include <conio.h>
#include "File.h"
#include <vector>

class Calendar :public ThisMoment
{
public:
	//Calendar(); //�����������
	
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
	std::string defineMonth(); //���������� ����������� �������� ������ �� ��� ������
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
	void writeToFile(std::string name_of_file); //������ ������ � ���� (����������� ����������� �������)
	void readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes); //���������� ������ �� ����� (����������� ����������� �������)
};

#endif