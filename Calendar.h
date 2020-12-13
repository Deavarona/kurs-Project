#ifndef CALENDAR_H
#define CALENDAR_H
#include <conio.h>
#include "ThisMoment.h"
#include "File.h"
#include "Tools.h"

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
	std::string defineShortNameOfMonth(int month_number); //Возвращает сокращенное название месяца по его номеру
	int inputDay(int month, int year); //Ввод дня срока выполнения задачи
	int inputMonth(int year); //Ввод месяца срока выполнения задачи
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
	int calculatePriority();
	int chooseTheNoteNumber(std::vector <Calendar>& note, int number_of_notes);
	double timeBeforeDeadline();
	void showNotesWithoutDeadline();

	void saveNoteInFile(std::string name_of_file); //Запись задачи в файл
	void readAllNotesFromFile(std::string name_of_file, std::vector <Calendar>&notes, int number_of_notes); //Считывание всех задач из файла
	void rewriteFile(std::string name_of_file, std::vector<Calendar>& notes, int number_of_notes);

	void showNote(Calendar&note); //Вывести заметку на консоль
	void showAllNotes(std::vector <Calendar>& note, int number_of_notes); //Вывести все заметки на консоль
	void showNotesWithDeadline(std::vector <Calendar>& note, int number_of_notes); //Вывести все заметки с дедлайном
	void showUnfulfilledNotes(std::vector<Calendar>& note, int number_of_notes); //Вывести невыполненные задачи
	void showNotesThisYear(std::vector<Calendar>& note, int number_of_notes);
	void showNotesThisMonth(std::vector<Calendar>& note, int number_of_notes);
	void showNotesThisDay(std::vector<Calendar>& note, int number_of_notes);
	void sortPriority(std::vector<Calendar>& note, int number_of_notes);

	void editNoteName(Calendar&note);
	void editNoteContent(Calendar& note);
	void editNoteDeadline(Calendar& note);
	void editNoteStatus(Calendar& note);
	void editNotePriority(Calendar& note);
	void deleteNote(std::vector<Calendar>& note, int note_number, int&number_of_notes);

	void whatTheDayToday();
	void todayTasks();
};

void addNote();

#endif