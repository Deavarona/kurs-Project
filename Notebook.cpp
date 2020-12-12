#include "Notebook.h"

std::string Notebook::inputString()
{
	std::string temp_string;
	std::getline(std::cin, temp_string);
	return temp_string;
}

//---------яеррепш----------

void Notebook::setNoteName(std::string note_name)
{
	m_note_name = note_name;
}
void Notebook::setNoteContent(std::string note_content)
{
	m_note_content = note_content;
}
void Notebook::setStatus(bool status)
{
	m_status = status;
}
void Notebook::setPriority(int priority)
{
	m_priority = priority;
}

//---------церрепш----------

std::string Notebook::getNoteName()
{
	return m_note_name;
}
std::string Notebook::getNoteContent()
{
	return m_note_content;
}
bool Notebook::getStatus()
{
	return m_status;
}
int Notebook::getPriority()
{
	return m_priority;
}