#ifndef CALENDAR_H
#define CALENDAR_H
#include <conio.h>
#include "ThisMoment.h"
#include "Tools.h"
#include "File.h"

class Calendar: public ThisMoment
{
public:
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
	std::string defineNameOfMonth(); //Возвращает сокращенное название месяца по его номеру
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
	void saveNoteInFile(std::string name_of_file); //Запись задачи в файл
	void readAllNotesFromFile(std::string name_of_file, std::vector <Calendar>&notes, int number_of_notes); //Считывание всех задач из файла
	void showNote(Calendar&note); //Вывести заметку на консоль
	void showAllNotes(std::vector <Calendar>& note, int number_of_notes); //Вывести все заметки на консоль
};

#endif