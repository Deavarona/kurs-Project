#include <iostream>
#include <Windows.h>
#include "Note.h"
#include "Calendar.h"
#include "File.h"
#include "Tools.h"
#include <vector>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	checkFileExisting(MAIN_FILE_NAME);

	int number_of_notes = defineNumberOfLinesAtFile(MAIN_FILE_NAME);
	std::vector <Calendar> note(number_of_notes);
	readFromFile(MAIN_FILE_NAME, note, number_of_notes);
	for (int i = 0; i < number_of_notes; i++)
	{
		std::cout << note.at(i).getNoteName() << " " << note.at(i).getNoteContent() << std::endl;
		std::cout << note.at(i).getStatus() << " " << note.at(i).getPriority() << std::endl;
		std::cout << note.at(i).getYear() << "/" << note.at(i).getMonth() << "/" << note.at(i).getDay() << " ";
		std::cout << note.at(i).getHour() << ":" << note.at(i).getMinute() << std::endl;
		std::cout << std::endl;
	}
}