#ifndef THISMOMENT_H
#define THISMOMENT_H
#include "Notebook.h"
#include <ctime>

class ThisMoment :public Notebook
{
protected:
	time_t right_now;
	tm right_now_struct;
	int m_current_day; //Текущий день
	int m_current_month; //Текущий месяц
	int m_current_year; //Текущий год
	int m_current_minute; //Текущая минута
	int m_current_hour; //Текущий час
public:
	ThisMoment(); //Конструктор
	void defineThisMoment(); //Определить текущие дату и время
};

#endif