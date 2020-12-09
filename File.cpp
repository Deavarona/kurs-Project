#include "File.h"

void checkFileExisting(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	if (!file.is_open())
	{
		std::ofstream new_file(name_of_file);
		new_file.close();
	}
	file.close();
}

int defineNumberOfLinesAtFile(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	
	std::string temp;
	int number_of_lines = 0;
	while (std::getline(file, temp, '\n'))
	{
		number_of_lines++;
	}
	return number_of_lines;
}

void writeToFoleNoteWithoutDeadline(std::string name_of_file, Note& note)
{
	std::string note_name = note.getNoteName();
	std::string note_content = note.getNoteContent();
	bool note_status = note.getStatus();
	int note_priority = note.getPriority();
	int note_deadline_year = UNKNOWN_VALUE;
	int note_deadline_month = UNKNOWN_VALUE;
	int note_deadline_day = UNKNOWN_VALUE;
	int note_deadline_hour = UNKNOWN_VALUE;
	int note_deadline_minute = UNKNOWN_VALUE;
	std::ofstream file(name_of_file, std::ios::app);
	file << note_name << " " << note_content << " " << note_status << " " << note_priority << " " << note_deadline_year << " " <<
		note_deadline_month << " " << note_deadline_day << " " << note_deadline_hour << " " << note_deadline_minute << std::endl;
	file.close();
}

void writeToFileNoteWithDeadline(std::string name_of_file, Calendar& note)
{
	std::string note_name = note.getNoteName();
	std::string note_content = note.getNoteContent();
	bool note_status = note.getStatus();
	int note_priority = note.getPriority();
	int note_deadline_year = note.getYear();
	int note_deadline_month = note.getMonth();
	int note_deadline_day = note.getDay();
	int note_deadline_hour = note.getHour();
	int note_deadline_minute = note.getMinute();
	std::ofstream file(name_of_file, std::ios::app);
	file << note_name << " " << note_content << " " << note_status << " " << note_priority << " " << note_deadline_year << " " <<
		note_deadline_month << " " << note_deadline_day << " " << note_deadline_hour << " " << note_deadline_minute << std::endl;
	file.close();
}

void showFileContent(std::string name_of_file)
{
	std::string temp;
	std::ifstream file(name_of_file, std::ios::in);
	while (!file.eof())
	{
		getline(file, temp, '\n');
		std::cout << temp << std::endl;
	}
	file.close();
}