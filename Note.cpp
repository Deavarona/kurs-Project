#include "Note.h"

Note::Note()
{
	
}

std::string Note::inputString()
{
	std::string temp_string;
	std::getline(std::cin, temp_string);
	return temp_string;
}


//---------яеррепш----------
void Note::setNoteName(std::string note_name)
{
	m_note_name = note_name;
}

void Note::setNoteContent(std::string note_content)
{
	m_note_content = note_content;
}

void Note::setStatus(bool status)
{
	m_status = status;
}

void Note::setPriority(int priority)
{
	m_priority = priority;
}


//---------церрепш----------
std::string Note::getNoteName()
{
	return m_note_name;
}

std::string Note::getNoteContent()
{
	return m_note_content;
}

bool Note::getStatus()
{
	return m_status;
}

int Note::getPriority()
{
	return m_priority;
}