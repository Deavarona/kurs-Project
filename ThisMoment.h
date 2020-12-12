#ifndef THISMOMENT_H
#define THISMOMENT_H
#include "Notebook.h"
#include <ctime>

class ThisMoment :public Notebook
{
protected:
	int m_current_day; //������� ����
	int m_current_month; //������� �����
	int m_current_year; //������� ���
	int m_current_minute; //������� ������
	int m_current_hour; //������� ���
public:
	ThisMoment(); //�����������
	void defineThisMoment(); //���������� ������� ���� � �����
};

#endif