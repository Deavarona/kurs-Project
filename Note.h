#ifndef NOTE_H
#define NOTE_H
#include "Tools.h"
#include <string>

class Note
{
private:
	std::string m_note_name=UNKNOWN_STRING; //�������� �������
	std::string m_note_content=UNKNOWN_STRING; //�������� �������
	bool m_status=false; //������ (���������/�� ���������)
	int m_priority=UNKNOWN_VALUE; //���������

public:
	Note();
	std::string inputString();
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
	virtual void createNote() = 0;
};

#endif