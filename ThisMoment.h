#ifndef THISMOMENT_H
#define THISMOMENT_H
#include "Notebook.h"
#include <ctime>
#include <iomanip>

class ThisMoment :public Notebook
{
protected:
	time_t right_now;
	tm right_now_struct;
	int m_current_day; //������� ����
	int m_current_month; //������� �����
	int m_current_year; //������� ���
	int m_current_minute; //������� ������
	int m_current_hour; //������� ���

	std::string month_name[12] = { "������", "�������", "����", "������", "���", "����", "����", "������", 
		"��������", "�������", "������", "�������" };
	std::string day_week_name[7] = { "��", "��", "��", "��", "��", "��", "��" };

public:
	ThisMoment(); //�����������

	int getCurrentYear();
	int getCurrentMonth();
	int getCurrentDay();

	void defineCurrentDayTime(); //���������� ������� ���� � �����
	int defineMaxDayInThatMonth(int month, int year); //���������� ������������ ���� ������
	void createCalendarMonth(int month, int year);
	void showCalendarCurrentMonth();
	void createCalendarYear();
};

#endif