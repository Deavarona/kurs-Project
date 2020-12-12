#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "Constants.h"
#include "Calendar.h"
#include <string>
#include <vector>

class Notebook
{
protected:
	std::string m_note_name = DEFAULT_VALUE_STRING; //Название заметки
	std::string m_note_content = DEFAULT_VALUE_STRING; //Описание заметки
	bool m_status = false; //Статус (выполнено/не выполнено)
	int m_priority = DEFAULT_VALUE; //Приоритет

public:
	//Notebook(); //Конструктор
	std::string inputString(); //Ввод строки
	virtual void createNote() = 0; //Создание заметки

	//virtual void writeToFile(std::string name_of_file) = 0; //Запись задачи в файл
	//virtual void readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes) = 0; //Считать задачу с файла

	//-----Сеттеры-----

	void setNoteName(std::string note_name);
	void setNoteContent(std::string note_content);
	void setStatus(bool status);
	void setPriority(int priority);

	//-----Геттеры-----

	std::string getNoteName();
	std::string getNoteContent();
	bool getStatus();
	int getPriority();
};

#endif