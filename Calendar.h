#ifndef CALENDAR_H
#define CALENDAR_H
#include <conio.h>
#include "ThisMoment.h"
#include "File.h"
#include "Tools.h"

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
	std::string defineShortNameOfMonth(int month_number); //���������� ����������� �������� ������ �� ��� ������
	int inputDay(int month, int year); //���� ��� ����� ���������� ������
	int inputMonth(int year); //���� ������ ����� ���������� ������
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
	int calculatePriority();
	int chooseTheNoteNumber(std::vector <Calendar>& note, int number_of_notes);
	double timeBeforeDeadline();
	void showNotesWithoutDeadline();

	void saveNoteInFile(std::string name_of_file); //������ ������ � ����
	void readAllNotesFromFile(std::string name_of_file, std::vector <Calendar>&notes, int number_of_notes); //���������� ���� ����� �� �����
	void rewriteFile(std::string name_of_file, std::vector<Calendar>& notes, int number_of_notes);

	void showNote(Calendar&note); //������� ������� �� �������
	void showAllNotes(std::vector <Calendar>& note, int number_of_notes); //������� ��� ������� �� �������
	void showNotesWithDeadline(std::vector <Calendar>& note, int number_of_notes); //������� ��� ������� � ���������
	void showUnfulfilledNotes(std::vector<Calendar>& note, int number_of_notes); //������� ������������� ������
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