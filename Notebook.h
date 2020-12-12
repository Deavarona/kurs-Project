#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "Constants.h"
#include <string>
#include <vector>

class Notebook
{
protected:
	std::string m_note_name = DEFAULT_VALUE_STRING; //�������� �������
	std::string m_note_content = DEFAULT_VALUE_STRING; //�������� �������
	bool m_status = false; //������ (���������/�� ���������)
	int m_priority = 0; //���������

public:
	std::string inputString(); //���� ������
	virtual void createNote() = 0; //�������� �������

	//-----�������-----

	void setNoteName(std::string note_name);
	void setNoteContent(std::string note_content);
	void setStatus(bool status);
	void setPriority(int priority);

	//-----�������-----

	std::string getNoteName();
	std::string getNoteContent();
	bool getStatus();
	int getPriority();
};

#endif