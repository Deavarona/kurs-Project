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
	int m_current_day; //Текущий день
	int m_current_month; //Текущий месяц
	int m_current_year; //Текущий год
	int m_current_minute; //Текущая минута
	int m_current_hour; //Текущий час

	std::string month_name[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", 
		"Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
	std::string day_week_name[7] = { "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС" };

public:
	ThisMoment(); //Конструктор

	int getCurrentYear();
	int getCurrentMonth();
	int getCurrentDay();

	void defineCurrentDayTime(); //Определить текущие дату и время
	int defineMaxDayInThatMonth(int month, int year); //Определить максимальный день месяца
	void createCalendarMonth(int month, int year);
	void showCalendarCurrentMonth();
	void createCalendarYear();
};

#endif