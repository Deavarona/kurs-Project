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

//void writeToFile(std::string name_of_file, Note& note)
//{
//	std::string note_name = note.getNoteName();
//	std::string note_content = note.getNoteContent();
//	bool note_status = note.getStatus();
//	int note_priority = note.getPriority();
//	int note_deadline_year = UNKNOWN_VALUE;
//	int note_deadline_month = UNKNOWN_VALUE;
//	int note_deadline_day = UNKNOWN_VALUE;
//	int note_deadline_hour = UNKNOWN_VALUE;
//	int note_deadline_minute = UNKNOWN_VALUE;
//	std::ofstream file(name_of_file, std::ios::app);
//	file << note_name << SPECIAL_SYMBOL  << " " << note_content << SPECIAL_SYMBOL << " " << note_status << " " << note_priority << " " << note_deadline_year << " " <<
//		note_deadline_month << " " << note_deadline_day << " " << note_deadline_hour << " " << note_deadline_minute << std::endl;
//	file.close();
//}

void writeToFile(std::string name_of_file, Calendar& note)
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
	file << note_name << SPECIAL_SYMBOL << " " << note_content << SPECIAL_SYMBOL << " " << note_status << " " << note_priority << " " << note_deadline_year << " " <<
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

//void readFromFile(std::string name_of_file, std::vector <Note>&note, int number_of_notes)
//{
//	std::string note_name;
//	std::string note_content;
//	bool note_status;
//	int note_priority;
//	int note_deadline_year;
//	int note_deadline_month;
//	int note_deadline_day;
//	int note_deadline_hour;
//	int note_deadline_minute;
//	std::ifstream file(name_of_file, std::ios::in);
//	for (int i = 0; i < number_of_notes; i++)
//	{
//		getline(file, note_name, '\'');
//		getline(file, note_content, '\'');
//		file >> note_status;
//		file >> note_priority;
//		file >> note_deadline_year;
//		file >> note_deadline_month;
//		file >> note_deadline_day;
//		file >> note_deadline_hour;
//		file >> note_deadline_minute;
//		note.at(i).setNoteName(note_name);
//		note.at(i).setNoteContent(note_content);
//		note.at(i).setStatus(note_status);
//		note.at(i).setPriority(note_priority);
//	}
//	file.close();
//}

void readFromFile(std::string name_of_file, std::vector <Calendar>& note, int number_of_notes)
{
	std::string note_name;
	std::string note_content;
	bool note_status;
	int note_priority;
	int note_deadline_year;
	int note_deadline_month;
	int note_deadline_day;
	int note_deadline_hour;
	int note_deadline_minute;
	std::ifstream file(name_of_file, std::ios::in);
	for (int i = 0; i < number_of_notes; i++)
	{
		getline(file, note_name, '\'');
		getline(file, note_content, '\'');
		file >> note_status;
		file >> note_priority;
		file >> note_deadline_year;
		file >> note_deadline_month;
		file >> note_deadline_day;
		file >> note_deadline_hour;
		file >> note_deadline_minute;
		note.at(i).setNoteName(note_name);
		note.at(i).setNoteContent(note_content);
		note.at(i).setStatus(note_status);
		note.at(i).setPriority(note_priority);
		note.at(i).setYear(note_deadline_year);
		note.at(i).setMonth(note_deadline_month);
		note.at(i).setDay(note_deadline_day);
		note.at(i).setHour(note_deadline_hour);
		note.at(i).setMinute(note_deadline_minute);
	}
	file.close();
}