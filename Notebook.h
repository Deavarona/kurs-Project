#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "Constants.h"
#include "Calendar.h"
#include <string>
#include <vector>

class Notebook
{
protected:
	std::string m_note_name = DEFAULT_VALUE_STRING; //�������� �������
	std::string m_note_content = DEFAULT_VALUE_STRING; //�������� �������
	bool m_status = false; //������ (���������/�� ���������)
	int m_priority = DEFAULT_VALUE; //���������

public:
	//Notebook(); //�����������
	std::string inputString(); //���� ������
	virtual void createNote() = 0; //�������� �������

	//virtual void writeToFile(std::string name_of_file) = 0; //������ ������ � ����
	//virtual void readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes) = 0; //������� ������ � �����

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