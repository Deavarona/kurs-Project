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
	//Calendar(); //Конструктор
	
	//-----ДАТА-----
private:
	int m_day = DEFAULT_VALUE; //День срока выполнения задачи
	int m_month = DEFAULT_VALUE; //Месяц срока выполнения задачи
	int m_year = DEFAULT_VALUE; //Год срока выполнения задачи
public:
	//-----Сеттеры-----
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//-----Геттеры-----
	int getDay();
	int getMonth();
	int getYear();
	//----------
	std::string defineMonth(); //Возвращает сокращенное название месяца по его номеру
	int inputDay(); //Ввод дня срока выполнения задачи
	int inputMonth(); //Ввод месяца срока выполнения задачи
	int inputYear(); //Ввод года срока выполнения задачи

	//-----ВРЕМЯ-----
private:
	int m_minute = DEFAULT_VALUE; //Минута срока выполнения задачи
	int m_hour = DEFAULT_VALUE; //Час срока выполнения задачи
public:
	//-----Сеттеры-----
	void setMinute(int minute);
	void setHour(int hour);
	//-----Геттеры-----
	int getMinute();
	int getHour();
	//----------
	int inputMinute(); //Ввод минуты срока выполнения задачи
	int inputHour(); //Ввод часа срока выполнения задачи

public:
	void createNote(); //Создание заметки (определение виртуальной функции)
	void writeToFile(std::string name_of_file); //Запись задачи в файл (определение виртуальной функции)
	void readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes); //Считывание задачи из файла (определение виртуальной функции)
};

#endif