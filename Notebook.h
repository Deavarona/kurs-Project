#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "Constants.h"
#include <string>
#include <vector>

class Notebook
{
protected:
	std::string m_note_name = DEFAULT_VALUE_STRING; //Название заметки
	std::string m_note_content = DEFAULT_VALUE_STRING; //Описание заметки
	bool m_status = false; //Статус (выполнено/не выполнено)
	int m_priority = 0; //Приоритет

public:
	std::string inputString(); //Ввод строки
	virtual void createNote() = 0; //Создание заметки

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